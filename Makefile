CXX= c++

CXXFLAGS= -Wall -Wextra -Werror -MMD

SRCS= $(wildcard *.cpp)

OBJS= ${SRCS:.cpp=.o}

OBJD= ${SRCS:.cpp=.d}

NAME= ft_containers

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS} ${OBJD}

fclean: clean
	rm -f ${NAME}

re: fclean
	make all

-include ${OBJD}

.PHONY: all clean fclean re