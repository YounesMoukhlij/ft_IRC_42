

#pragma once

#include "Headers.hpp"


class Server
{
	private:
		std::string						_port;
		struct addrinfo					_params;
		int								_poll_fd;
		std::string						_password;
		int								_socket_fd;
		int								_port_number;
		std::vector<struct pollfd> pollArray;




	public:
		~Server();
		Server(std::string port, std::string password);


		void	ShutServer();
		void	startServer();
		void	ServerConnection();
		void	setSocketParameter();

};









