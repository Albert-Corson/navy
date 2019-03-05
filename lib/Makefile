##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	./get_char_pos.c	\
		./my_copycat.c		\
		./my_memcmp.c		\
		./my_calloc.c		\
		./my_putchar.c		\
		./my_putstr.c		\
		./my_strcpy.c		\
		./my_strdup.c		\
		./my_puterror.c		\
		./my_strlen.c		\
		./my_tabledup.c		\
		./my_getnbr.c		\
		./my_put_err_nbr.c	\
		./my_putchar_err.c	\
		./my_nisnum.c		\
		./get_line.c		\
		./get_input.c		\
		./my_putnbr.c		\
		./my_memset.c		\
		./my_bin.c			\
		./my_pow.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+= -I ../include

NAME	=	libmy.a

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

all:    $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean re fclean