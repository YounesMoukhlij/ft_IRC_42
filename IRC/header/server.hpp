

#pragma once

#include "Headers.hpp"


class Server
{
	private:
		std::string						_port;
		int								
		std::string						_password;
		int								_socket_fd;
		struct addrinfo					_params;
		// struct addrinfo					*socketPara;



	public:
		~Server();
		Server(std::string port, std::string password);


		int		startServer();
		void	ServerConnection();
		void	setSocketParameter();

		class server : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};









