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

test:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "so ein schoener Name" "22"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "so ein schoener Name" "151"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "so ein schoener Name" "0"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "so ein schoener Name" "-3"

.PHONY: all clean fclean re

