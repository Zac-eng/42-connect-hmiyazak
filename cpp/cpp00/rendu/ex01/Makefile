NAME=phonebook
CPP=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS= ./srcs/main.cpp ./srcs/add_func.cpp ./srcs/search_func.cpp
OBJS= $(SRCS:.cpp=.o)
INCLUDES= includes

%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

