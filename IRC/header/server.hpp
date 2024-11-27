

#pragma once

#include "headers.hpp"


class Server
{
	private:
		std::string						_port;
		std::string						_password;
		std::string						_datetime;
		int								_socket_fd;
		struct addrinfo					_params;



	public:
		~Server();
		startServer();
		setSocketParameter();
		Server(std::string port, std::string password);
};


Server::startServer()
{
	_socket_fd = socket(_params->ai_family, _params->_type, _params->_protocol);
	if (_socket_fd == -1)
	{
		std::cerr << "Error : The socket creation failed !" << std::endl;
		exit(EXIT_FAILURE);
	}
}

Server::setSocketParameter()
{
	_params-> = AF_INET;  // We choose Ipv4
	_params->_type = SOCK_STREAM; // We choose to work with TCP stream sockets
	_params->_protocol = AI_PASSIVE;
}

