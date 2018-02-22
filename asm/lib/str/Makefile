##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	source/my_put_nbr.c		\
		source/my_putchar.c		\
		source/my_putstr.c		\
		source/my_revstr.c		\
		source/my_strlen.c		\
		source/my_str_to_word_tab.c	\
		source/my_display_tab.c		\
		source/my_atoi.c		\
		source/my_str_is_num.c		\
		source/my_cleaner.c		\
		source/my_puterr.c		\
		source/my_strcmp.c		\
		source/my_strncmp.c		\
		source/my_str_is_alpha.c	\
		source/shift_tab.c	\
		source/my_puterr_nbr.c\
		source/my_puterr.c\


OBJ	=	$(SRC:.c=.o)

NAME	=	libstr.a

CFLAGS	=	-W -Wall -Wextra -I includes

LDFLAGS	=	-lstr

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re all
