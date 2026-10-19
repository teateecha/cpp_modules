NAME		=	bureaucrat
CXX			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp \

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
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "Guenter" "22"

.PHONY: all clean fclean re test

