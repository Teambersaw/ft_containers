CXX= c++

CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD

SRCS= main.cpp
SRCS2= main2.cpp

OBJS= ${SRCS:.cpp=.o}
OBJS2= ${SRCS2:.cpp=.o}

OBJD= ${SRCS:.cpp=.d}
OBJD2= ${SRCS2:.cpp=.d}

NAME= ft_containers
NAME_STD = ft_containers_std

%.o : %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

all:	${NAME} ${NAME_STD}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

${NAME_STD}: ${OBJS2}
	${CXX} ${CXXFLAGS} ${OBJS2} -o ${NAME_STD}

clean:
	rm -f ${OBJS} ${OBJD} ${OBJS2} ${OBJD2}

fclean: clean
	rm -f ${NAME_STD} ${NAME}

re: fclean
	$(MAKE) all

-include ${OBJD} ${OBJD2}


.PHONY: all clean fclean re