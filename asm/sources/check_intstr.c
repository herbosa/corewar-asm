/*
** EPITECH PROJECT, 2017
** check_initsr.c
** File description:
** check instructions functions
*/

#include "asm.h"

int count_coma(char *str)
{
	int i = 0;
	int nbr = 0;

	for (i = 0; str[i]; i = i + 1)
		if (str[i] == ',')
			nbr = nbr + 1;
	return (nbr);
}

int verify_instr(char *str, int i)
{
	char *instr = my_strndup(str, i);

	if (my_strcmp(instr, "live") || my_strcmp(instr, "ld") ||
		my_strcmp(instr, "st") || my_strcmp(instr, "add") ||
		my_strcmp(instr, "sub") || my_strcmp(instr, "and") ||
		my_strcmp(instr, "or") || my_strcmp(instr, "xor") ||
		my_strcmp(instr, "zjmp") || my_strcmp(instr, "ldi") ||
		my_strcmp(instr, "sti") || my_strcmp(instr, "fork") ||
		my_strcmp(instr, "lld") || my_strcmp(instr, "lldi") ||
		my_strcmp(instr, "lfork") || my_strcmp(instr, "aff")) {
		check_nbr_arg(str);
		return (1);
	} else
		return (0);
}

void check_instr_thrd(char **tab, int *x, int *y, int *i)
{
	for (*i = 0; *i < *x; *i = *i + 1)
		if (!is_label_char(tab[*y][*i]) && tab[*y][0] != '#')
			exit (84);
}

void check_intstr_sec(char **tab, int *x, int *y)
{
	int i = 0;

	for (*x = 1; tab[*y][*x]; *x = *x + 1) {
		if (tab[*y][*x] == ':' && tab[*y][*x - 1] != '%')
			check_instr_thrd(tab, x, y, &i);
	}
}

void check_instr(char **tab)
{
	int x = 0;
	int y = 0;

	for (y = 0; tab[y] && tab[y][0]; y = y + 1)
		check_intstr_sec(tab, &x, &y);
	check_valid_instr(tab);
}
