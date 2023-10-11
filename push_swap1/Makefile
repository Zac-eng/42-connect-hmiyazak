# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 12:17:42 by hmiyazak          #+#    #+#              #
#    Updated: 2023/10/11 20:41:09 by hmiyazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c input_handlers/*.c stack_handlers/*.c
LIBFT = libft.a
LIBFTDIR = libft
RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR) all
	mv ./libft/libft.a .

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)
	$(RM) libft.a

re: fclean all

.PHONY: all clean fclean re debug

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -O0 -g3
endif

debug: re