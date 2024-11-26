

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
	_domain = AF_INET;		  // We choose Ipv4
	_t = SOCK_STREAM; // We choose to work with TCP stream sockets
	ai_flags = AI_PASSIVE;
}

