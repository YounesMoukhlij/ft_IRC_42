

#include "../header/Server.hpp"

Server::Server(std::string port, std::string password) : _port(port), _password(password)
{
    std::cout << "The Server is Getting UP ... " << std::endl;

}

Server::~Server()
{
    std::cout << "The Server is shutting down ... " << std::endl;
}

void	Server::startServer()
{
	_socket_fd = socket(_params.sin_family, _params.sin_addr.s_addr , _params.sin_protocol);
	if (_socket_fd == -1)
	{
		std::cerr << "Error : The socket creation failed !" << std::endl;
		exit(EXIT_FAILURE);
	}
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

}

void	Server::setSocketParameter()
{
	_params.sin_family = AF_INET;  // We choose Ipv4
	_params.si_socktype = SOCK_STREAM; // We choose to work with TCP stream sockets
	_params.si_protocol = AI_PASSIVE;
}

const char *Server::server::what(void) const throw()
{
    return ("Error : The server failed to start !");
}

void	Server::ServerConnection()
{
	while (1)
	{
		std::cout << "The server is waiting for a connection ..." << std::endl;
		if (accept(_socket_fd, 0x0, 0x0) == -1)
		{
			std::cerr << "Error : The accept failed !" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}
