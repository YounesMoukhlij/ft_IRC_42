#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Error: Socket creation failed!" << std::endl;
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Error: Socket bind failed!" << std::endl;
        close(sockfd);
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        std::cerr << "Error: Socket listen failed!" << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    // Accept a connection (blocking call)
    int client_sock = accept(sockfd, NULL, NULL);
    if (client_sock == -1) {
        std::cerr << "Error: Socket accept failed!" << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "Client connected!" << std::endl;

    // Close sockets
    close(client_sock);
    close(sockfd);

    return 0;
}
