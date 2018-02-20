##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for matchstick
##

SRC	=	sources/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CFLAGS	=	-W -Wall -Wextra -I includes -g

LDFLAGS	=	-L ./lib/print -lprint -L ./lib/str -lstr

all:	libmake $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

libmake:
	make -C ./lib/print
	make -C ./lib/str

clean:
	rm -f $(OBJ)
	make clean -C ./lib/print
	make clean -C ./lib/str

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/print
	make fclean -C ./lib/str

re:	fclean all

.PHONY:	fclean clean all re libmake
