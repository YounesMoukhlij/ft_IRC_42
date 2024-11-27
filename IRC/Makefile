OBJ = ${SRC:.cpp=.o}

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = irc.cpp
	  ./classes/server.cpp
	  ./classes/client.cpp

NAME = ircserv

HEADER = irc.hpp
		 classes/server.hpp
		 classes/client.hpp
		 header/


all : ${NAME}


%.o: %.cpp ${HEADER}
	@echo "\033[30m Compiling ...\033[0m"
	@c++ ${CPPFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	@echo "\033[32m Linking ...\033[0m"
	@c++ ${CPPFLAGS} $^ -o $@

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean
