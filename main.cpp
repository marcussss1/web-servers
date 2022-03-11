#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdio.h>
#include <string>

int main(int argc, char** argv) {
    char *opts = "-h:-p:-d:"; // доступные опции, каждая принимает аргумент
    int opt; 
    std::string directory;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    while((opt = getopt(argc, argv, opts)) != -1) { 
        switch(opt) {
            case 'h': 
                addr.sin_addr.s_addr = htonl(atoi(optarg));
                break;
            case 'p':
                addr.sin_port = htons(atoi(optarg));
                break;
            case 'd':
                directory = optarg;
                break;
        }
    }
    std::cout << "Попытка подключения...\n";
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd == -1) {
        std::cerr << "Ошибка при создании сокета\n";
        return -1;
    }
    if(bind(socket_fd, (struct sockaddr*) (&addr), sizeof(addr)) == -1) {
        close(socket_fd);
        std::cerr << "Ошибка при подключении к клиенту\n";
        return -1;
    }
    if (listen(socket_fd, SOMAXCONN) == -1) {
        close(socket_fd);
        std::cerr << "Ошибка при прослушивании сокета\n";
        return -1;
    }
    std::cout << "Успешно подключено\n";
    return 0;
}