##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	sources/main.c\
		sources/write_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	=	-W -Wall -Wextra -I include

LDFLAGS	=	-L ./lib/str -lstr

all:	libmake $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

libmake:
	make -C ./lib/str

clean:
	rm -f $(OBJ)
	make clean -C ./lib/str

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/str

re:	fclean all

.PHONY:	clean fclean re all libmake
