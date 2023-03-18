CXX= c++

CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -MMD

SRCS= main.cpp

FT_DIR= objs/ft/
STD_DIR= objs/std/
D_OBJS= objs

OBJS_FT= $(patsubst %.cpp, $(FT_DIR)%.o, $(SRCS))
OBJS_STD= $(patsubst %.cpp, $(STD_DIR)%.o, $(SRCS))

OBJD_FT= $(patsubst %.cpp, $(FT_DIR)%.d, $(SRCS))
OBJD_STD= $(patsubst %.cpp, $(STD_DIR)%.d, $(SRCS))

NAME= containers_ft
NAME_STD= containers_std

$(FT_DIR)%.o: %.cpp
	@mkdir -p $(FT_DIR)
	$(CXX) $(CXXFLAGS) -D NS=ft -c $< -o $@

$(STD_DIR)%.o: %.cpp
	@mkdir -p $(STD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME) $(NAME_STD)

$(NAME): $(OBJS_FT)
	$(CXX) $(CXXFLAGS) $(OBJS_FT) -o $(NAME)

$(NAME_STD): $(OBJS_STD)
	$(CXX) $(CXXFLAGS) $(OBJS_STD) -o $(NAME_STD)

clean:
	rm -rf $(D_OBJS)

fclean: clean
	rm -rf $(NAME) $(NAME_STD)

re: fclean
	$(MAKE) all

-include $(OBJD_FT) $(OBJD_STD)

.PHONY: all clean fclean re time