#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

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

namespace CLIENT
{
    enum ERR
    {
        OK  = 0,

        ERROR
    };
};

const int MAX_MSG_LEN   = 1024;

/// Starts client
int StartClient();

#endif // CLIENT_H_INCLUDED
