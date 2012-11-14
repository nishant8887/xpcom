#ifndef __CommWebsocket_h__
#define __CommWebsocket_h__

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <map>
#include <jsoncpp/json/json.h>
#include <libwebsockets.h>
#include <pthread.h>

using namespace std;
using namespace Json;

class MainComponent;

class WebsocketServer
{
        struct libwebsocket_context *context;
        int port;
        pthread_t ws_thread;
        unsigned char *buffer;
    public:        
        int start();
        void execute();
        static int callback_http(struct libwebsocket_context *, struct libwebsocket *, enum libwebsocket_callback_reasons, void *, void *, size_t);
        static int callback_gigacomm(struct libwebsocket_context *, struct libwebsocket *, enum libwebsocket_callback_reasons, void *, void *, size_t);
        void SendMessage(string);
        WebsocketServer(MainComponent *, int);
        ~WebsocketServer();
};

enum demo_protocols {
	PROTOCOL_HTTP = 0,
	PROTOCOL_GIGACOMM,
	DEMO_PROTOCOL_COUNT
};

struct per_session_data__gigacomm
{
        int is_enabled;
        string *id;
};

static struct libwebsocket_protocols protocols[] = {    
    {
        "http-only",
        WebsocketServer::callback_http,
        0
    },
    {
        "gigacomm",
        WebsocketServer::callback_gigacomm,
        sizeof(struct per_session_data__gigacomm)
    },
    {
        NULL, NULL, 0
    }
};
#endif
