##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	sources/main.c			\
		sources/write_nbr.c		\
		sources/cmd_parser.c		\
		sources/get_next_line.c		\
		sources/get_next_line_2.c	\
		sources/error_handling.c	\
		sources/tab.c			\
		sources/ldi_intstr.c		\
		sources/lldi_instr.c		\
		sources/sti_instr.c		\
		sources/convert_cmd_param.c	\
		sources/xor.c			\
		sources/or.c			\
		sources/cmd_sub_add.c		\
		sources/cmd_st_fork.c		\
		sources/cmd.c			\
		sources/wrt_size.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	=	-g -W -Wall -Wextra -I includes

LDFLAGS	=	-g -L ./lib/str -lstr

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
