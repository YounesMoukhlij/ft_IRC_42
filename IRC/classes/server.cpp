

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
	_socket_fd = socket(_params.ai_family, _params.ai_socktype, _params.ai_protocol);
	if (_socket_fd == -1)
	{
		std::cerr << "Error : The socket creation failed !" << std::endl;
		exit(EXIT_FAILURE);
	}
    if (bind(_socket_fd, _params.ai_addr, _params.ai_addrlen) == -1)
    {
        std::cerr << "Error : The bind failed !" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (listen(_socket_fd, 10) == -1)
    {
        std::cerr << "Error : The listen failed !" << std::endl;
        exit(EXIT_FAILURE);
    }
    if ()

}

void	Server::setSocketParameter()
{
	_params.ai_family = AF_INET;  // We choose Ipv4
	_params.ai_socktype = SOCK_STREAM; // We choose to work with TCP stream sockets
	_params.ai_protocol = AI_PASSIVE;
}

const char *Server::server::what(void) const throw()
{
    return ("Error : The server failed to start !");
}
