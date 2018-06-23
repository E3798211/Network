#include <sys/socket.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <netinet/in.h>

#include <iostream>
#include <stdio.h>

#include <signal.h>

#include "Server/Server.h"
#include "Client/Client.h"

int main()
{
    StartServer();
//    StartClient();
}
