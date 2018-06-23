#include "Client.h"

int StartClient()
{
    // Opening socket

    int client = socket(AF_INET, SOCK_STREAM, 0);
    if( client < 0 )
    {
        printf("\x1b[31m"
                "Failed to open client socket."
                "\n\x1b[0m");
        return CLIENT::ERROR;
    }
    else
    {
        DBG printf("Client socket opened: %d\n", client);
    }

    // Setting address

    sockaddr_in server_addr = {};
    server_addr.sin_family  = AF_INET;
    server_addr.sin_port    = htons(3000);
    inet_pton(AF_INET, "192.168.10.102", &(server_addr.sin_addr));

    if( connect(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0 )
    {
        perror("connect");
        exit(2);
    }

    char message[1024] = "Hey, there!\n";
    char buf[1024] = {};

    std::cout << "THIS MOMENT: " << send(client, message, sizeof(message), 0);
    // recv(client, buf,     sizeof(buf),     0);

}
