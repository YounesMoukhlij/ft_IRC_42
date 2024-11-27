

#include "../header/Server.hpp"

Server::Server(std::string port, std::string password) : _port(port), _password(password)
{
    std::cout << "The Server is Getting UP ... " << std::endl;

}

Server::~Server()
{
    std::cout << "The Server is shutting down ... " << std::endl;
}

int Server::startServer()
{
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);



	_socket_fd = socket(AF_INET, SOCK_STREAM , 0);
	// _socket_fd = socket(socketPara->ai_family, socketPara->ai_socktype , socketPara->ai_protocol);
	if (_socket_fd == -1)
	{
		std::cerr << "Error : The socket creation failed !" << std::endl;
        return (EXIT_FAILURE);
	}

    // if (bind(_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    if (bind(_server_socket_fd, _servinfo->ai_addr, _servinfo->ai_addrlen))
    {
        std::cerr << "Error: Socket bind failed!" << std::endl;
        // close(_socket_fd);
        return (EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(_socket_fd, 5) == -1)
    {
        std::cerr << "Error: Socket listen failed!" << std::endl;
        // close(_socket_fd);
        return (EXIT_FAILURE);
    }

    std::cout << "Server is listening on port 8080..." << std::endl;

    // Accept a connection (blocking call)
    int client_sock = accept(_socket_fd, NULL, NULL);
    if (client_sock == -1)
    {
        std::cerr << "Error: Socket accept failed!" << std::endl;
        // close(_socket_fd);
        return (EXIT_FAILURE);
    }
    std::cout << "Client connected!" << std::endl;
    return (EXIT_SUCCESS);


}

void	Server::setSocketParameter()
{
	_params.ai_family = AF_INET;  // We choose Ipv4
	_params.ai_socktype = SOCK_STREAM; // We choose to work with TCP stream sockets
	_params.ai_protocol = AI_PASSIVE; // We choose to work with TCP stream sockets
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
