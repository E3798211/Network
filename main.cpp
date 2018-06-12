#include <sys/socket.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <netinet/in.h>

#include <iostream>
#include <stdio.h>

#include <signal.h>

#define   __DEBUG__
#ifdef    __DEBUG__
    #define DBG
#else
    #define DBG if(0)
#endif // __DEBUG__

namespace ERRORS
{
    int SOCKET_INIT_FAILED  = -1;
    int BINDING_FAILED      = -1;
}

void handler(int s)
{
    printf("Caught SIGPIPE\n");
}

int main()
{
    signal(SIGPIPE, handler);

    int socket_fd = socket(AF_INET6, SOCK_STREAM, 0);
    if (socket_fd == ERRORS::SOCKET_INIT_FAILED)
    {
        std::cout << "Failed to create socket\n";
        return ERRORS::SOCKET_INIT_FAILED;
    }
    else
    {
        DBG std::cout << "Socket file descriptor opened: " << socket_fd << "\n";
    }

    // 192.168.1.180

    sockaddr_in server_addr     = {};
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(3425);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(socket_fd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        std::cout << "Binding failed\n";
        return ERRORS::BINDING_FAILED;
    }
    else
    {
        DBG std::cout << "Binded successfuly\n";
    }

    std::cout << write(socket_fd, "test", 3);
    std::cout << send(socket_fd, "aaaa", 5, 0);
    perror("sendind");
}

