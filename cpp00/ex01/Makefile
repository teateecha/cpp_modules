NAME		=	phonebook
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Contact.cpp \
				PhoneBook.cpp

INC			=	Contact.hpp \
				PhoneBook.hpp

OBJ			=	$(SRC:.c=.o)

all:	$(NAME)

# Linking
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# compiling
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
