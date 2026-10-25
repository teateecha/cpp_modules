NAME		=	converter
CXX			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				ScalarConverter.cpp \

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
	$(NAME)


.PHONY: all clean fclean re test

