

#include "header/IRC.hpp"

void    signal_handler(int signal)
{
    
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Error : The program started like this ./ircserv port password !" << std::endl;
        return (EXIT_FAILURE);
    }
	signal(SIGINT, signal_handler);



    return (EXIT_SUCCESS);
}
