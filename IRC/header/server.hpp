

#pragma once

#include "headers.hpp"


class Server
{
	private:
		std::string						_port;
		std::string						_password;
		std::string						_datetime;

	public:
		Server(std::string port, std::string password);
		Server();
		~Server();
};

