#include "Server.h"

int StartServer()
{
    // Opening socket

    int server = socket(AF_INET, SOCK_STREAM, 0);
    if( server < 0 )
    {
        printf("\x1b[31m"
                "Failed to open server socket."
                "\n\x1b[0m");
        return SERVER::ERROR;
    }
    else
    {
        DBG printf("Server socket opened: %d\n", server);
    }

    // Setting address

    sockaddr_in server_addr = {};
    server_addr.sin_family  = AF_INET;
    server_addr.sin_port    = htons(3000);
    inet_pton(AF_INET, "192.168.10.102", &(server_addr.sin_addr));

    // Binding

    if( bind(server, (sockaddr*)&server_addr, sizeof(server_addr)) != 0 )
    {
        printf("\x1b[31m"
                "Failed to bind server socket."
                "\n\x1b[0m");
        perror("Error");

        close(server);
        return SERVER::ERROR;
    }
    else
    {
        DBG printf("Server socket binded successfully\n");

        char str[16] = {};
        inet_ntop(AF_INET, &(server_addr.sin_addr), str, INET_ADDRSTRLEN);
        printf("Address: %s\n", str);
    }

    // Listening

    if( listen(server, MAX_QUEUE_LEN) < 0 )
    {
        printf("\x1b[31m"
                "Server listening failed.\n"
                "\n\x1b[0m");
        perror("Error");

        close(server);
        return SERVER::ERROR;
    }
    else
    {
        DBG printf("Server is listening.\n\n", MAX_QUEUE_LEN);
    }

    // Processing incoming messages

    char message[MAX_BUFF_LEN]  = {};
    char  answer[MAX_BUFF_LEN]  = {};

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
            return SERVER::ERROR;
        }
        else
        {
            while(true)
            {
                recv(next_socket, message, MAX_BUFF_LEN, 0);
                printf("c> %s\n",  message);

                printf("s> ");
                fgets(message, MAX_BUFF_LEN, stdin);
                printf("\n");

                send(next_socket, message, MAX_BUFF_LEN, 0);
            }
        }

        close(next_socket);
    }

    close(next_socket);

    return SERVER::OK;
}
