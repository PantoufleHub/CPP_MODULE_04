NAME		= polymorph
SRCS		= main.cpp Animal.cpp Cat.cpp Dog.cpp
FLAGS		= -Wall -Werror -Wextra -std=c++98
CC			= c++


all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(FLAGS) -o $(NAME)

clean:
	rm -rf *.dSYM *.o *test .vscode

fclean:	clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	@echo compiling file $<...
	@$(CC) $(FLAGS) $< -o $@

.PHONY: all run clean fclean re