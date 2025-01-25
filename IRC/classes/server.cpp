

#include "../header/Headers.hpp"

Server::Server(std::string port, std::string password) : _port(port), _password(password)
{
    std::cout << "The Server is ON ... " << std::endl;
    setSocketParameter();

}

Server::~Server()
{
    std::cout << "The Server is shutting down ... " << std::endl;
}

void    Server::startServer()
{
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(_port_number);



	_socket_fd = socket(AF_INET, SOCK_STREAM , 0);
	if (_socket_fd == -1)
		throw (std::logic_error("Error : The socket creation failed !"));

    if (bind(_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        throw (std::logic_error("Error: Socket bind failed!"));

    if (listen(_socket_fd, 5) == -1)
        throw (std::logic_error("Error: Socket listen failed!"));

    std::cout << "Server is listening on port : "<< _port << std::endl << "\n \t Waiting ... "<< std::endl;



}

void	Server::setSocketParameter()
{
	_params.ai_family = AF_INET;  // We choose Ipv4
	_params.ai_socktype = SOCK_STREAM; // We choose to work with TCP stream sockets
	_params.ai_flags = AI_PASSIVE; // We choose to work with TCP stream sockets
    _port_number = std::stoi(_port);
    _poll_fd = 0;
    _client_fd = 0;
}



void	Server::ServerConnection()
{

    // char            buffer[1024];

    puts("DEBUG HERE");
    pollArray[0].fd = _socket_fd ;
    pollArray[0].events = POLLIN ;

	while (_socket_fd != -1)
	{
        // _poll_fd = poll(&pollArray[0], pollArray.size(), -1);
        // if (_poll_fd == -1)
        //     throw (std::logic_error("Error : The poll failed !"));
        std::cout << " -> " << _poll_fd << std::endl ;


        // if (pollArray[0].revents & POLLIN)
        // {
		//     std::cout << "The server is waiting for a connection ..." << std::endl;
        //     _client_fd = accept(_socket_fd, 0x0, 0x0);
		//     if (_client_fd == -1)
		//     	throw (std::logic_error("Error : The accept failed !"));
        //     std::cout << " ~~~ BOYAAH Client connected! ~~~" << std::endl;
        // }
    }
    close(_client_fd);

	}


void	Server::ShutServer()
{
    close(_socket_fd);
}



    // Read data from the client
            // ssize_t bytes_received = recv(pollArray[0].fd, buffer, sizeof(buffer) - 1, 0);
            //     if (bytes_received > 0)
            //     {
            //         buffer[bytes_received] = '\0';  // Null-terminate the received message
            //         std::cout << "Received from client: " << buffer << std::endl;

            //         // Echo the message back to the client
            //         send(pollArray[0].fd, buffer, bytes_received, 0);
            //     }
            //     else if (bytes_received == 0)
            //     {
            //         std::cout << "Client disconnected." << std::endl;
            //         close(pollArray[0].fd);  // Close the socket
            //         // pollArray.erase(pollArray.begin() + i);  // Remove client from poll array
            //         // --i;  // Adjust index after removal
            //     }
            //     else
            //     {
            //         std::cerr << "Error receiving data from client." << std::endl;
            //     }
