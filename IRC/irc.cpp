

#include "header/IRC.hpp"

void    signal_handler(int signal)
{
    if (signal == SIGINT)
    {
        std::cout << "Welcome any time." << std::endl;
        exit(0);
    }
}

int    InputParsing(int argc, char **argv)
{
    try
    {
        if (std::atoi(argv[1]) < 1024 || std::atoi(argv[1]) > 65535)
            throw std::logic_error("Error : The port number must be between 1024 and 65535 !");
        if (strlen(argv[1]) < 4 || strlen(argv[1]) > 5)
            throw std::logic_error("Error : The port number must be between 4 and 5 digits !");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return (0);


}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Error : The program started like this ./ircserv port password !" << std::endl;
        return (EXIT_FAILURE);
    }
    InputParsing(argc, argv);

	signal(SIGINT, signal_handler);


    Server  server(argv[1], argv[2]);

    if (server.startServer())
    {
        std::cerr << "Error : The server failed to start !" << std::endl;
        return (EXIT_FAILURE);
    }

    try
    {
        server.ServerConnection();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }




    return (EXIT_SUCCESS);
}
