NAME	= bank
CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf

SRCS	= tests.cpp Account.cpp

all: $(NAME)

$(NAME):
	@ $(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean re