##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	./src/main.c			\
		./src/error.c			\
		./src/signal/connect.c	\
		./src/board/boardgen.c	\
		./src/board/parser.c	\
		./src/board/render.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+= -I include

LIB =	-L./lib -lmy

NAME	=	navy

$(NAME):	$(OBJ)
	make -C ./lib
	gcc -o $(NAME) $(OBJ) $(LIB)

all:    $(NAME)

clean:
	make clean -C ./lib
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean re fclean