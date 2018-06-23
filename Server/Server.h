#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <iostream>
#include <stdio.h>

#define DEBUG__
#ifdef  DEBUG__
    #define DBG
#else
    #define DBG if(0)
#endif // DEBUG__

namespace SERVER
{
    enum ERR
    {
        OK  = 0,

        ERROR
    };
};

const int MAX_QUEUE_LEN = 1024;
const int MAX_BUFF_LEN  = 1024;

/// Starts listening server
int StartServer();

#endif // SERVER_H_INCLUDED
