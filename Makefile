##
## EPITECH PROJECT, 2018
## a
## File description:
## a
##

all:
	make -C asm/
clean:
	make clean -C asm/
fclean:
	make fclean -C asm

re:	fclean all

.PHONY:	all clean fclean re
