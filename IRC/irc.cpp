

#include "header/IRC.hpp"

void    signal_handler(int signal)
{
    (void) signal;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Error : The program started like this ./ircserv port password !" << std::endl;
        return (EXIT_FAILURE);
    }
	signal(SIGINT, signal_handler);


    Server  server(argv[1], argv[2]);

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
