NAME=claptrap
CPP=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS= main.cpp ClapTrap.cpp
OBJS= $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
