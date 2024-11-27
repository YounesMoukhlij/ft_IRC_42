

#pragma once

#include "Headers.hpp"


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
		Server(std::string port, std::string password);


		void	startServer();
		void	ServerConnection();
		void	setSocketParameter();

		class server : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

void	Server::ServerConnection()
{
	while (1)
}







