##
## EPITECH PROJECT, 2018
## a
## File description:
## a
##

all:
	make -C asm/
	make -C corewar/
clean:
	make clean -C asm/
	make clean -C corewar/
fclean:
	make fclean -C asm
	make fclean -C corewar/

re:	fclean all

.PHONY:	all clean fclean re
