CXX= c++

CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD

SRCS= main.cpp

OBJS= ${SRCS:.cpp=.o}

OBJD= ${SRCS:.cpp=.d}

NAME= ft_containers

NAME2= ft_containers_std

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} -D NS=ft ${OBJS} -o ${NAME}

${NAME2}: ${OBJS}
	${CXX} ${CXXFLAGS} -D NS=std ${OBJS} -o ${NAME2}

all: ${NAME} ${NAME2}

clean:
	rm -f ${OBJS} ${OBJD}

fclean: clean
	rm -f ${NAME} ${NAME2}

re: fclean
	make all

-include ${OBJD}

.PHONY: all clean fclean re