#include "CommWebsocket.h"
#include "MainComponent.h"

#define CHECKROOT if(!root.isObject()) return 0;
#define INT(X,Y) if(!getInt(X, root[#Y])) return 0;
#define STRING(X,Y) if(!getString(X, root[#Y])) return 0;
#define OSTRING(X,Y) if(!getOString(X, root[#Y])) return 0;

MainComponent *gtmc;
map<string, string> ClientMap;
map<string, string>::iterator iter;
string applicationpath;

class serverMsg : public nsRunnable
{
	public:
	serverMsg(string ldata, MainComponent *lmcpt) : data(ldata), mcpt(lmcpt)
	{
	}

	NS_IMETHOD Run()
	{
	    nsCString msgdata(data.c_str(), data.length());
	    mcpt->jsutils->RaiseEvent(msgdata);
	}

	private:
	string data;
	MainComponent *mcpt;
};

void initialize_path()
{
    pid_t pid;
    pid = getpid();
    char linkname[1024];
    sprintf((char *)linkname, "/proc/%i/exe", pid);

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    readlink(linkname, buf, sizeof(buf)-1);

    string pathstr(buf);
    applicationpath = pathstr.substr(0,pathstr.find_last_of("/\\"));
    cout << "The path for executable is " << applicationpath << endl;
}

void copytobuffer(unsigned char *&lbuffer, unsigned char *&msg_start, int &msg_size, string str)
{
    int str_size = str.length();
    lbuffer = new unsigned char[LWS_SEND_BUFFER_PRE_PADDING + str_size + LWS_SEND_BUFFER_POST_PADDING];
    msg_start = &lbuffer[LWS_SEND_BUFFER_PRE_PADDING];
    str_size = sprintf((char *)msg_start, "%s", str.c_str());
    msg_size = str_size;
}

int getDouble(double &value, Value root)
{
    if(root.type() == 3) {
	value = root.asDouble();
	return 1;
    }
    return 0;
}

int getInt(int &value, Value root)
{
    if(root.type() == 1) {
	value = root.asInt();
	return 1;
    }
    return 0;
}

int getString(string &value, Value root)
{
    if(root.type() == 4) {
	value = root.asString();
	return 1;
    }
    return 0;
}

int getOString(string &value, Value root)
{
    FastWriter writer;
    
    if(root.type() == 7) {
	value = writer.write(root);
	return 1;
    } else if(root.type() == 4) {
	value = "\""+root.asString()+"\"";
	return 1;
    }
    return 0;
}

void SendMessageToServer(string type, string message, string client)
{
    ostringstream gtservermessage;
    gtservermessage << "{ \"type\": \"" << type << "\", \"message\": " << message << ", \"client\": \"" << client << "\" }\0";
    nsCOMPtr<nsIRunnable> srvmsg = new serverMsg(gtservermessage.str(),gtmc);
    nsresult resvalue = NS_DispatchToMainThread(srvmsg);
}

WebsocketServer::WebsocketServer(MainComponent *lgtmc, int portnumber)
{
    port = portnumber;
    gtmc = lgtmc;
}

WebsocketServer::~WebsocketServer()
{

}    

int WebsocketServer::callback_http(struct libwebsocket_context *context, struct libwebsocket *wsi, enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
{
    string mainpath(applicationpath);
    string request, resrcpath, extension, mime;
    ostringstream clientlist;
    
    switch (reason) {
        case LWS_CALLBACK_HTTP: {
	    request = (char *)in;
	    cout << "Http request made. -> " << request << endl;
	    
	    if(!request.compare("/")) {
		resrcpath = "/html/controller/index.html";
	    } else if(!request.compare("/server")) {
		resrcpath = "/html/server/index.html";
	    } else if(!request.compare("/clientlist")) {
		clientlist << "{ \"clients\": [ ";
		for( iter=ClientMap.begin(); iter != ClientMap.end(); iter++ ) {
		    clientlist << "{ \"id\": \"" << (*iter).first << "\", \"info\": " << (*iter).second << " },";
		}
		clientlist << "{ NULL } ] }";
		libwebsocket_write(wsi, (unsigned char *)clientlist.str().c_str(), clientlist.str().length(), LWS_WRITE_HTTP);
		libwebsocket_close_and_free_session(context, wsi, LWS_CLOSE_STATUS_NORMAL);
		return 0;
	    } else {
		resrcpath = request;
	    }
	    
	    mainpath += "/static";
	    mainpath += resrcpath;
	    size_t dotloc = mainpath.find_last_of(".");
	    if(dotloc <= mainpath.length()) {
		extension = mainpath.substr(dotloc);
	    }
	    
	    if(!extension.compare(".png")) {
		mime = "image/png";
	    } else if(!extension.compare(".jpg")) {
		mime = "image/jpg";
	    } else if(!extension.compare(".gif")) {
		mime = "image/gif";
	    } else if(!extension.compare(".css")) {
		mime = "text/css";
	    } else if(!extension.compare(".html")) {
		mime = "text/html";
	    } else if(!extension.compare(".js")) {
		mime = "text/js";
	    } else {
		mime = "text/plain";
	    }
	    
	    libwebsockets_serve_http_file(wsi, mainpath.c_str(), mime.c_str());
            libwebsocket_close_and_free_session(context, wsi, LWS_CLOSE_STATUS_NORMAL);
            break;
        }
        default:
            break;
    }
    return 0;
}

int WebsocketServer::callback_gigacomm(struct libwebsocket_context *context, struct libwebsocket *wsi, enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
{
    struct per_session_data__gigacomm *client;
    
    unsigned char *client_buffer;
    unsigned char *msg_start;
    int msg_size;
    
    int key, x, y;
    string msg, recvmsg, type, clientid, origid;
    ostringstream jsonmsg;
    
    Value root;
    Reader reader;
    
    client = (struct per_session_data__gigacomm *)user;

    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED: {
            cout << "Connection established." << endl;
	    client->is_enabled = 0;
	    client->id = new string("");
            break;
        }
	case LWS_CALLBACK_BROADCAST: {
	    cout << "Broadcast message received." << endl;
	    cout << (char *)in << endl;
	    
	    msg = (char *)in;
	    origid = (*client->id);
	    reader.parse(msg,root);
	    CHECKROOT
	    
	    STRING(clientid,client)
	    OSTRING(recvmsg, message)
	    
	    if(((!clientid.compare(origid))||(!clientid.compare("-1")))&&(origid.compare(""))) {
		copytobuffer(client_buffer, msg_start, msg_size, recvmsg);
		libwebsocket_write(wsi, msg_start, msg_size, LWS_WRITE_TEXT);
	    }
	    break;
	}
        case LWS_CALLBACK_RECEIVE: {
	    cout << "Message received." << endl;
	    cout << (char *)in << endl;
	    
	    msg = (char *)in;
	    origid = (*client->id);
	    reader.parse(msg,root);
	    CHECKROOT
	    
	    STRING(type,type)
	    
	    if(!type.compare("client_info")) {
		STRING(clientid,uuid) OSTRING(recvmsg,info)
		if((!ClientMap[clientid].compare(""))&&(clientid.compare(""))) {
		    ClientMap[clientid] = recvmsg;
		    delete(client->id);
		    client->id = new string(clientid);
		    client->is_enabled = 1;
		    
		    SendMessageToServer("client_connect",recvmsg,clientid);
		    
		    jsonmsg << "{ \"message\": { \"type\": \"client_connect\", \"connected\": \"true\", \"info\": " << ClientMap[clientid] << " }, \"client\": \"-1\" }";
		    copytobuffer(client_buffer, msg_start, msg_size, jsonmsg.str());
		    libwebsockets_broadcast(&protocols[PROTOCOL_GIGACOMM],msg_start,msg_size);
		    return 0;
		}
		
		jsonmsg << "{ \"type\": \"client_connect\", \"connected\": \"false\" }";
		copytobuffer(client_buffer, msg_start, msg_size, jsonmsg.str());
		libwebsocket_write(wsi, msg_start, msg_size, LWS_WRITE_TEXT);
	    }
	    
	    if(!client->is_enabled) return 0;
	    
	    if(!type.compare("mouse_rel")) {
		INT(x,x) INT(y,y)
		gtmc->Movemouse(x,y);
	    } else if(!type.compare("mouse_abs")) {
		INT(x,x) INT(y,y)
		gtmc->SetMousePosition(x,y);
	    } else if(!type.compare("mouse_clk")) {
		INT(key,button)
		gtmc->MouseClick(key);
	    } else if(!type.compare("keyboard")) {
		INT(key,keycode)
		gtmc->KeyDownUp(key);
	    } else if(!type.compare("clientmsg")) {
		STRING(clientid,toclient) OSTRING(recvmsg,message)
		jsonmsg << "{ \"message\": " << recvmsg << ", \"client\": \"" << clientid << "\" }";
		copytobuffer(client_buffer, msg_start, msg_size, jsonmsg.str());
		libwebsockets_broadcast(&protocols[PROTOCOL_GIGACOMM],msg_start,msg_size);
	    } else if(!type.compare("gamemsg")) {
		OSTRING(recvmsg,message);
		SendMessageToServer("client_msg",recvmsg,origid);
	    } else if(!type.compare("nativemsg")) {
		STRING(recvmsg,message);
		gtmc->SendNativeMessage(recvmsg.c_str());	
	    } else {
		cout << "Invalid message." << endl;
	    }
            break;
        }
        case LWS_CALLBACK_FILTER_PROTOCOL_CONNECTION: {
            cout << "Connect request received." << endl;
            break;
        }
        case LWS_CALLBACK_CLOSED: {
            cout << "Connection closed." << endl;
	    origid = (*client->id);
	    SendMessageToServer("client_disconnect",ClientMap[origid],origid);

	    jsonmsg << "{ \"message\": { \"type\": \"client_disconnect\", \"info\": " << ClientMap[origid] << " }, \"client\": \"-1\" }";
	    copytobuffer(client_buffer, msg_start, msg_size, jsonmsg.str());
	    libwebsockets_broadcast(&protocols[PROTOCOL_GIGACOMM],msg_start,msg_size);
	    
	    ClientMap.erase(origid);
            break;
        }
        default:
            cout << "Error handling callback (" << reason << ")." << endl;
    }
    return 0;
}

void WebsocketServer::execute()
{
    const char *interface = NULL;
    const char *certificate_path = NULL;
    const char *key_path = NULL;
    int opts = 0;

    context = libwebsocket_create_context(port, interface, protocols, libwebsocket_internal_extensions, certificate_path, key_path, -1, -1, opts);
    
    if (context == NULL) {
        cout << "Initialization of socket failed." << endl;
	SendMessageToServer("native","\"websocket_error\"","native");
        return;
    }
    
    gtmc->serverstarted = true;
    SendMessageToServer("native","\"websocket_opened\"","native");
    
    while (1) {
        libwebsocket_service(context, 50);
    }
    libwebsocket_context_destroy(context);
}

void WebsocketServer::SendMessage(string message)
{
    int msg_size;
    unsigned char *msg_start;
    copytobuffer(buffer, msg_start, msg_size, message);
    libwebsockets_broadcast(&protocols[PROTOCOL_GIGACOMM],msg_start,msg_size);
}

void* wss_thread_proc(void* wsobj)
{
    WebsocketServer *_this = (WebsocketServer *)wsobj;
    _this->execute();
    gtmc->serverstarted = false;
}

int WebsocketServer::start()
{
    initialize_path();
    pthread_attr_t  attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    pthread_create(&ws_thread, &attr, wss_thread_proc, this);
    pthread_attr_destroy(&attr);
    return 0;
}

