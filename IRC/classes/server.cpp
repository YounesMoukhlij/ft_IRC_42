

#include "../header/Server.hpp"

Server::Server(std::string port, std::string password) : _port(port), _password(password)
{
    std::cout << "The Server is shutting down ... " << std::endl;

}

Server::~Server()
{
    std::cout << "The Server is shutting down ... " << std::endl;
}

void	Server::startServer()
{
	_socket_fd = socket(_params.ai_family, _params.ai_socktype, _params.ai_protocol);
	if (_socket_fd == -1)
	{
		std::cerr << "Error : The socket creation failed !" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	Server::setSocketParameter()
{
	_params.ai_family = AF_INET;  // We choose Ipv4
	_params.ai_socktype = SOCK_STREAM; // We choose to work with TCP stream sockets
	_params.ai_protocol = AI_PASSIVE;
}
