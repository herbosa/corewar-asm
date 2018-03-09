/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** check functions
*/

#include "asm.h"

void check_nbr_arg_3(char *str)
{
	if ((my_strncmp("lldi ", str, 5) ||
	my_strncmp("sti ", str, 4) ||
	my_strncmp("ldi ", str, 4) ||
	my_strncmp("xor ", str, 4) ||
	my_strncmp("or ", str, 3) ||
	my_strncmp("add ", str, 4) ||
	my_strncmp("sub ", str, 4) ||
	my_strncmp("and ", str, 4))
	&& count_coma(str) != 2) {
		my_puterr("Invalid number of argument in :\t");
		my_puterr(str);
		my_puterr("\n");
		exit(84);
	}
}

void check_nbr_arg_2(char *str)
{
	if ((my_strncmp("st ", str, 3) ||
	my_strncmp("ld ", str, 3) ||
	my_strncmp("lld ", str, 4))
	&& count_coma(str) != 1) {
		my_puterr("Invalid number of argument in :\t");
		my_puterr(str);
		my_puterr("\n");
		exit(84);
	}
}

void check_nbr_arg(char *str)
{
	if ((my_strncmp("live ", str, 5) ||
	my_strncmp("zjmp ", str, 5) ||
	my_strncmp("fork ", str, 5) ||
	my_strncmp("lfork ", str, 6) ||
	my_strncmp("aff ", str, 4))
	&& count_coma(str) != 0) {
		my_puterr("Invalid number of argument in :\t");
		my_puterr(str);
		my_puterr("\n");
		exit(84);
	}
	check_nbr_arg_2(str);
	check_nbr_arg_3(str);
}

void check_valid_instr_if(char **tab, int y, int x)
{
	if (tab[y][0] != '.' && tab[y][0] != '#' && tab[y][x] == ' ') {
		if (!verify_instr(tab[y], x)) {
			my_puterr("Unknow instruction :\t");
			my_puterr(tab[y]);
			my_puterr("\n");
			exit (84);
		}
	}
}

void check_valid_instr(char **tab)
{
	int x = 0;
	int y = 0;

	for (y = 2; tab[y]; y = y + 1)
		for (x = 0; tab[y][x]; x = x + 1)
			check_valid_instr_if(tab, y, x);
}
