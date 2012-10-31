#include "websocket.h"
#include "MKComp.h"

MKComponent *mksim;
int ClientMap[MAX_CLIENTS];
string resrcpath;

void initFilePath() {
    //char path[256];
    //getcwd(path,256);

    pid_t pid;
    pid = getpid();
    char linkname[256];
    sprintf((char *)linkname, "/proc/%i/exe", pid);

    char buf[256];
    readlink(linkname, buf, 256);

    string pathstr;
    pathstr.append(buf);
    resrcpath = pathstr.substr(0,pathstr.find_last_of("/\\"));
    cout << "The path for executable is " << resrcpath << endl;

    resrcpath.append("/static/html/snake-control.html");
}

void initMap()
{
    for(int i=0; i<MAX_CLIENTS; i++) ClientMap[i] = 0;
}

int getClientId()
{
    int i;
    for(i=0; i<MAX_CLIENTS; i++) {
        if(ClientMap[i] == 0) break;
    }
    
    if(i == MAX_CLIENTS) {
        return 170;
    } else {
        ClientMap[i] = 1;
        return i;
    }
}

int requestId(int x)
{
    if(x < MAX_CLIENTS) {
        if(ClientMap[x] == 0) {
            ClientMap[x] = 1;
            return x;
        }
    }
    return getClientId();
}

void clearId(int x)
{
    if(x < MAX_CLIENTS) {
        ClientMap[x] = 0;
    }
}

struct per_session_data__mkmouse
{
    int is_enabled;
    int clientid;
};

static struct libwebsocket_protocols protocols[] = {    
    {
        "http-only",
        WebsocketServer::callback_http,
        0
    },
    {
        "mkmouse",
        WebsocketServer::callback_mkmouse,
        sizeof(struct per_session_data__mkmouse)
    },
    {
        NULL, NULL, 0
    }
};

WebsocketServer::WebsocketServer(MKComponent *lmksim)
{
    mksim = lmksim;
/*    pthread_attr_t  attr;
    int returnVal;
    returnVal = pthread_attr_init(&attr);
    returnVal = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_mutex_init(&ws_threadMutex, NULL);
    cout << pthread_mutex_lock(&ws_threadMutex) << endl;
    cout << pthread_mutex_trylock(&ws_threadMutex) << endl;
    cout << "Pthread create..." << endl;
    int threadError = pthread_create(&ws_aThread, &attr, &WebsocketServer::wsthreadProc, this);
    returnVal = pthread_attr_destroy(&attr);
    */
}

WebsocketServer::~WebsocketServer()
{
    pthread_mutex_destroy(&ws_threadMutex);
}    
int WebsocketServer::callback_http(struct libwebsocket_context *context, struct libwebsocket *wsi, enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
{
    switch (reason) {
        case LWS_CALLBACK_HTTP: {
            libwebsockets_serve_http_file(wsi, resrcpath.c_str(), "html");
            libwebsocket_close_and_free_session(context, wsi, LWS_CLOSE_STATUS_NORMAL);
            break;
        }
        default:
            break;
    }
    return 0;
}

int WebsocketServer::callback_mkmouse(struct libwebsocket_context *context, struct libwebsocket *wsi, enum libwebsocket_callback_reasons reason, void *user, void *in, size_t len)
{
    struct per_session_data__mkmouse *client;
    int n;
    unsigned char buf[LWS_SEND_BUFFER_PRE_PADDING + 512 + LWS_SEND_BUFFER_POST_PADDING];
	unsigned char *p = &buf[LWS_SEND_BUFFER_PRE_PADDING];
    
    client = (struct per_session_data__mkmouse *)user;

    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED: {
            cout << "Connection established..." << endl;
            client->is_enabled = 1;
            client->clientid = 170;
            break;
        }           
        case LWS_CALLBACK_RECEIVE: {
        
            if(client->is_enabled) {
                n = sprintf((char *)p, "%s", (char *)in);
                string jstr = (char *)p;
                //cout << jstr << endl;
                Json::Value root;
                Json::Reader reader;
                bool parsingSuccessful = reader.parse(jstr, root);

                if(root["type"] == "mouse") {
                    if(root["subtype"] == "rel") {
                        mksim->Movemouse(root["x"].asInt(),root["y"].asInt());
                    } else {
                        mksim->SetMousePosition(root["x"].asInt(),root["y"].asInt());
                    }
                        
                    if(root["button"].asInt() == 1) mksim->MouseClick(1);
                    
                } else if(root["type"] == "keyboard") {
                    mksim->KeyDownUp(root["keycode"].asInt());
                } else if(root["type"] == "event") {
                    client->clientid = root["clientid"].asInt();
                    mksim->SendEventToDOM(root["subtype"].asString(),root["clientid"].asInt());
                    nsCOMPtr<nsIRunnable> event = NS_NewRunnableMethod(mksim, &MKComponent::ExecuteEvent);
                    nsresult rv = NS_DispatchToMainThread(event);
                } else if(root["type"] == "game") {
                    if(root["subtype"] == "reg") {
                        client->clientid = requestId(root["clientid"].asInt());
                        mksim->SendEventToDOM("regclient",client->clientid);
                        nsCOMPtr<nsIRunnable> event = NS_NewRunnableMethod(mksim, &MKComponent::ExecuteEvent);
                        nsresult rv = NS_DispatchToMainThread(event);
                    } else if(root["subtype"] == "quit") {
                        mksim->SendEventToDOM("unregclient",root["clientid"].asInt());
                        nsCOMPtr<nsIRunnable> event = NS_NewRunnableMethod(mksim, &MKComponent::ExecuteEvent);
                        nsresult rv = NS_DispatchToMainThread(event);
                        clearId(root["clientid"].asInt());
                        client->clientid = 170;
                    }
                    n = sprintf((char *)p, "%s %d %s", "{ \"type\" : \"game\", \"clientid\" :", client->clientid, "}");
                    libwebsocket_write(wsi, p, n, LWS_WRITE_TEXT);
                } else {
                    cout << "Unknown message: " << (char *)p << endl;
                }
            }
            break;
        }
        case LWS_CALLBACK_FILTER_PROTOCOL_CONNECTION: {
            cout << "Connect request received..." << endl;
            break;
        }
        case LWS_CALLBACK_CLOSED: {
            cout << "Connection closed..." << endl;
            break;
        }
        default:
            cout << "Error handling callback (" << reason << ")" << endl;
    }
    return 0;
}

void WebsocketServer::execute()
{
    cout << "In Server execute..." << endl;
    const char *interface = NULL;
    const char *cert_path = NULL;
    const char *key_path = NULL;
    int opts = 0;
    
    this->context = libwebsocket_create_context(this->port, interface, protocols, libwebsocket_internal_extensions, cert_path, key_path, -1, -1, opts);
    
    if (context == NULL) {
        cout << "Socket initialization failed..." << endl;
        return;
    }
    
    cout << "Starting server..." << endl;
    int i=0;
    while (1) {
        libwebsocket_service(context, 50);
    }
    
    libwebsocket_context_destroy(context);
}

void* WebsocketServer::wsthreadProc(void* wsobj)
{
   WebsocketServer *_this = (WebsocketServer *)wsobj;
   //cout << "In threadproc: " << pthread_mutex_trylock(&(_this->ws_threadMutex)) << endl;
   //pthread_mutex_lock(&(_this->ws_threadMutex));
   _this->execute();
   pthread_mutex_unlock(&(_this->ws_threadMutex));
}

int WebsocketServer::start()
{
    /*pthread_mutex_unlock(&ws_threadMutex);
    cout << pthread_mutex_trylock(&ws_threadMutex) << endl;
    cout << "In Server start..." << endl;*/

    initFilePath();

    pthread_attr_t  attr;
    int returnVal;
    returnVal = pthread_attr_init(&attr);
    returnVal = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_mutex_init(&ws_threadMutex, NULL);
    pthread_mutex_lock(&ws_threadMutex);
    int threadError = pthread_create(&ws_aThread, &attr, &WebsocketServer::wsthreadProc, this);
    returnVal = pthread_attr_destroy(&attr);
    return 0;
}

