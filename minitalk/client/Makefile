NAME = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c ../libft.a
INCLUDE = -I ../libft
RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -o $@

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re