

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
		setParameter
		Server(std::string port, std::string password);
};

