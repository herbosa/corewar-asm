/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** error_handling.c
*/

#include "asm.h"

void disp_syntax_err(int nb)
{
	my_puterr("Syntax error at line ");
	my_puterr_nbr(nb);
	my_puterr(".\n");
}

int display_header_err(int bo)
{
	if (!bo) {
		my_puterr(".name missing from header.\n");
		return (84);
	} else if (bo) {
		my_puterr(".comment missing from header.\n");
		return (84);
	}
	return (84);
}