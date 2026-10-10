NAME		=	bureaucrat
CXX			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Bureaucrat.cpp \

OBJ			=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Guenter" "22"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "TooLow" "151"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "TooHigh" "0"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "SuperBoss" "1"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "CoffeMaker" "150"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "God" "-3"

.PHONY: all clean fclean re

