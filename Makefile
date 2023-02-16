CXX= c++

CXXFLAGS= -Wall -Wextra -Werror -MMD

HEADER= *.hpp

SRCS= *.cpp 

OBJS= ${SRCS:.cpp=.o}

OBJD= ${SRCS:.cpp=.d}

NAME= ft_containers

${NAME}: ${OBJS} ${HEADER}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm ${OBJS} ${OBJD}

fclean: clean
	rm ${NAME}

re: fclean
	make all

-include ${OBJD}

.PHONY: all clean fclean re