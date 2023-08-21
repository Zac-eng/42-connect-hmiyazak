NAME = minitalk
CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENTSRCS = ./client
SERVERSRCS = ./server
LIBFTDIR = ./libft
LIBFT = libft.a
RM = rm -rf

#+++++general+++++

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):
	make -C $(CLIENTSRCS) make
	mv $(CLIENTSRCS)/client .
$(SERVER): $(LIBFT)
	make -C $(SERVERSRCS) make
	mv $(SERVERSRCS)/server .

clean:
	$(RM) $(OBJS)
	make -C $(LIBFTDIR) clean
	make -C $(CLIENTSRCS) clean
	make -C $(SERVERSRCS) clean
fclean: clean
	$(RM) 
	make -C $(LIBFTDIR) fclean
	make -C $(CLIENTSRCS) fclean
	make -C $(SERVERSRCS) fclean
re: clean fclean
	make -C $(LIBFTDIR) re
	make -C $(CLIENTSRCS) re
	make -C $(SERVERSRCS) re
#+++++libft+++++

$(LIBFT):
	make -C $(LIBFTDIR) all
	mv ./libft/libft.a .

#++++++++++++++++

.PHONY: all clean fclean re
