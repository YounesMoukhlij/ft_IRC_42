

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
// li fhaam yfahmna m3ah had l3ilm  ... IPV4 who am i to understand this *_*
void	Server::setSocketParameter()
{
	_params.ai_family = AF_INET;  // We choose Ipv4
	_params.ai_socktype = SOCK_STREAM; // We choose to work with TCP stream sockets
	_params.ai_flags = AI_PASSIVE; // We choose to work with TCP stream sockets
    _port_number = std::stoi(_port);
    _poll_fd = 0;
    _client_fd = 0;
}

void Server::ServerConnection()
{
    char buffer[2048];

    (void) buffer;


    server_poll.fd = _socket_fd;
    server_poll.events = POLLIN;
    pollArray.push_back(server_poll);
    int j = 0;
    // while maa7ad socket khdama lmotor khdaam kayt7aam f ram eela walo, irc galek hh  rslna lmsg w dwina bkri
    // while fiha kulchi, connection between clients and this server
    while (_socket_fd != -1)
    {
        // Wait for clients ,, the poll handles I/O of a socket
        _poll_fd = poll(&pollArray[0], pollArray.size(), -1);
        if (_poll_fd == -1)
            throw (std::logic_error("Error: The poll failed!"));


        /*
            --> partie one
            -- > Check if the server socket is ready (new connection) !!!!!
        */
        if (pollArray[0].revents & POLLIN)
        {
            std::cout << "The server is waiting for a connection ..." << std::endl;
            _client_fd = accept(_socket_fd, 0, 0);
            if (_client_fd == -1)
                throw (std::logic_error("Error: The accept failed!"));


            // Add the client socket to the poll array to read data from it
            client_poll.fd = _client_fd;
            client_poll.events = POLLIN;
            pollArray.push_back(client_poll); // ADD client to the container, we dont forget that the server is on pollArray[0]
            j++;
            std::cout << "\n  ~~~ Connection Established. ~~~" << std::endl;
            std::cout << "\n  ~~~ Client : [" << j << "]" << std::endl;
        }

        /*
            --> partie two
            -- > discussion between many clients and this damned server
        */
        for (size_t i = 1; i < pollArray.size(); ++i)
        {
            if (pollArray[i].fd < 0) // JUST making sure if the fd is correctto
            {
                std::cerr << "Invalid client socket detected at index [" << i << "]" <<  std::endl;
                continue;  // we Skip invalid sockets
            }

            // If the client socket has data to read from the serverrr
            if (pollArray[i].revents & POLLIN)
            {
                // ila wsl mssg men eend client had recv katkhdm
                ssize_t bytes_received = recv(pollArray[i].fd, buffer, sizeof(buffer) - 1, 0);
                if (bytes_received > 0)
                {
                    buffer[bytes_received] = '\0'; // hadi katssema hot no9ta eela l7arf hhh men niytk kat9ra f hadchi hhhhhhhhhh
                    std::cout << "Message received from client [" << i << "] : "<< buffer << std::endl;

                    // prinnnnnt the message back to the client, to make the client feels good about his legendary msg hh
                    send(pollArray[i].fd, "message delivered.", 18, 0);
                    // ha lmsg dyalk wsalna ziiiidech nchuffech leekch ash kayn men baaad ? waaaaalo 3a tiriri m3a bnt tmaaaaraaaaa
                }
                // if mawsslt ta weza 
                else
                {
                    std::cerr << "Error receiving data from client." << std::endl;
                }
            }
        }
    }
}



void	Server::ShutServer()
{
    close(_socket_fd);
}



