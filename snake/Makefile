##
## ARTHUR MASSANES PROJECT, 2019
## snake
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/snake.c	\
		src/node.c	\
		src/input.c	\
		src/draw.c

OBJ	=	$(SRC:.c=.o)

NAME	=	 snake

HEAD	=	-I./include

LIB	=	-lncurses

all:	$(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRC) $(HEAD) $(LIB)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
