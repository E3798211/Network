#include <sys/socket.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <netinet/in.h>

#include <iostream>
#include <stdio.h>

#include <signal.h>

#include "Server/Server.h"

int main()
{
    /*

    // Opening socket

    int server = socket(AF_INET, SOCK_STREAM, 0);
    if( server < 0 )
    {
        printf("\x1b[31m"
                "Failed to open server socket."
                "\n\x1b[0m");
        exit(-1);
    }
    else
    {
        DBG printf("Server socket opened: %d\n", server);
    }

    // Setting address

    sockaddr_in server_addr = {};
    server_addr.sin_family  = AF_INET;
    server_addr.sin_port    = 8888;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Binding

    if( bind(server, (sockaddr*)&server_addr, sizeof(server_addr)) != 0 )
    {
        printf("\x1b[31m"
                "Failed to bind server socket."
                "\n\x1b[0m");
        perror("Error");

        close(server);
        exit(-1);
    }
    else
    {
        DBG printf("Server socket binded successfully\n");
    }

    // Listening

    if( listen(server, MAX_QUEUE_LEN) < 0 )
    {
        printf("\x1b[31m"
                "Server listening failed.\n"
                "\n\x1b[0m");
        perror("Error");

        close(server);
        exit(-1);
    }
    else
    {
        DBG printf("Server is listening. Max queue length: %d\n", MAX_QUEUE_LEN);
    }

    // Processing incoming messages

    char message_buffer[MAX_BUFF_LEN] = {};

    int next_socket = -1;
    while(true)
    {
        next_socket = accept(server, NULL, NULL);
        if( next_socket < 0 )
        {
            printf("\x1b[31m"
                "Failed to open socket."
                "\n\x1b[0m");

            close(server);
            exit(-1);
        }
        else
        {
            recv(next_socket, message_buffer, MAX_BUFF_LEN, 0);
            printf("Message: '%s'\n", message_buffer);
        }
    }

    close(next_socket);

    */

    StartServer();
}
