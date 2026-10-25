NAME = converter
CXX = cc
FLAGS = -Wall Wextra -Werror -cpp98 #must be different too
SRC = main.cpp \
	  ScalarConverter.cpp \

OBJ = $(SRC.cpp=.o) # i have no clue about this

all : $(NAME)

NAME : OBJ
	$(CC) $(FLAGS) OBJ -o $(NAME)

OBJ : SRC
	$(CC) $(FLAGS) $@ -o $>

clean :
	rm -r OBJ

fclean : clean
	rm $(NAME)

re : fclean all

test : re
	$(NAME)
