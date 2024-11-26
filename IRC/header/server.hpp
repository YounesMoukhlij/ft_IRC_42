

#pragma once

#include "headers.hpp"


class Server
{
	private:
		std::string						_port;
		std::string						_password;
		std::string						_datetime;
		int								_socket_fd;
		int 							_domain;
		int 							_type;
		int 							_protocol;



	public:
		~Server();
		startServer();
		setSocketParameter();
		Server(std::string port, std::string password);
};


Server::startServer()
{
	_socket_fd = socket()
}

Server::setSocketParameter()
{
	_domain = AF_INET;  // We choose Ipv4
	_type = SOCK_STREAM; // We choose to work with TCP stream sockets
	_protocol = AI_PASSIVE;
}

