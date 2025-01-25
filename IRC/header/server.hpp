

#pragma once

#include "Headers.hpp"


class Server
{
	private:
		std::string						_port;
		int								_port_number;
		std::string						_password;
		int								_socket_fd;
		struct addrinfo					_params;
		std::vector<struct pollfd> pollAr;




	public:
		~Server();
		Server(std::string port, std::string password);


		void	ShutServer();
		void	startServer();
		void	ServerConnection();
		void	setSocketParameter();

};









