

#pragma once

#include "headers.hpp"


class Server
{
	private:
		std::string						_port;
		std::string						_password;
		std::string						_datetime;
		int								_socket_fd;

	public:
		~Server();
		startServer();
		setSocketParameter();
		Server(std::string port, std::string password);
};


Server::startServer()
{

}

Server::setSocketParameter()
{

}


