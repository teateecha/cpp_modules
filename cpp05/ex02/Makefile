NAME		=	bureaucrat
CXX			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm \
				PresidentialPardonForm \

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

# usage: arg1: burocrat name, arg2: burocrat grade, arg3: form name, \
		arg4 form grade required to sign, arg5 form grade required to execute" << std::endl;
test: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Guenter" "22" "NormalForm" "140" "140"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Guenter" "24" "FormA" "23" "24"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Guenter" "22" "NonFom" "151" "150"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Guenter" "22" "NonFom" "150" "151"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Margret" "22" "superForm" "0" "3"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Margret" "22" "superForm" "3" "0"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "CoffeMaker" "150" "FormC" "149" "150"

.PHONY: all clean fclean re test

