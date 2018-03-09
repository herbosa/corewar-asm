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

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	fclean clean all re
