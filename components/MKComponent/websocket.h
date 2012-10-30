#ifndef __websocket_h__
#define __websocket_h__

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <jsoncpp/json/json.h>
#include <libwebsockets.h>
#include <pthread.h>

#define RESOURCE_PATH "/home/nishant8887/Documents/Repositories/xpcom/htmls/mkcontroller.html"
#define MAX_CLIENTS 100
using namespace std;

class MKComponent;

class WebsocketServer
{
        struct libwebsocket_context *context;
        pthread_t ws_aThread;
        pthread_mutex_t ws_threadMutex;
    public:
        int port;
        int start();
        void execute();
        static int callback_http(struct libwebsocket_context *, struct libwebsocket *, enum libwebsocket_callback_reasons, void *, void *, size_t);
        static int callback_mkmouse(struct libwebsocket_context *, struct libwebsocket *, enum libwebsocket_callback_reasons, void *, void *, size_t);
        static void* wsthreadProc(void *);
        WebsocketServer(MKComponent *);
        ~WebsocketServer();
};

#endif
