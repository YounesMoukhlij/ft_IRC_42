

#include "header/IRC.hpp"

void    signal_handler(int signal)
{
    if (signal == SIGINT)
    {
        std::cout << "Welcome any time." << std::endl;
        exit(0);
    }
}

void    InputParsing(cha)

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Error : The program started like this ./ircserv port password !" << std::endl;
        return (EXIT_FAILURE);
    }
    InputParsing(argv);

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
