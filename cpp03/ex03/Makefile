NAME		=	claptrap
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp

OBJ			=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

shadow: CFLAGS += -Wshadow
shadow: re

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re shadow valgrind

