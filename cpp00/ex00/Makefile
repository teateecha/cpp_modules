NAME		=	megaphone
CC			=	cc #check if this is the right compiler
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS			=	megaphone.cpp
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix, $(OBJ))

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
