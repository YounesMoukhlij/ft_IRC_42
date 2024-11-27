

#include "../Header/Server.hpp"

Server::Server(std::string port, std::string password) : _port(port), _password(password)
{
    setSocketParameter();
    startServer();
}
{

}

Server::~Server()
{
    std::cout << "The Server is shutting down ... " << std::endl;
}
