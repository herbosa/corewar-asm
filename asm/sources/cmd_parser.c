/*
** EPITECH PROJECT, 2018
** cmd_parser.c
** File description:
** cmd_parser.c
*/

#include "asm.h"

int file_parser(char **file)
{
	int i = 0;

	while (file[i]) {
		file[i] = my_cleaner(file[i]);
		i = i + 1;
	}
	while (file[0][0] == '#')
		shift_tab(file, 0);
	if (!my_strncmp(file[0], ".name ", 6))
		return (84);
	if (!my_strncmp(file[1], ".comment ", 9))
		return (84);
	code_parser(file);
}

void code_parser(char **file)
{
	int i = 0;

	while (file[3][i]) {
		
	}
}

op_t cmd_parser(char *str, op_t op_tab[])
{
	op_t cmd;


}

void shift_tab(char **tab, int i)
{
	while (tab[i + 1]) {
		tab[i] = malloc(sizeof(char*) * (my_strlen(tab[i + 1]) + 1));
		tab[i] = my_strcpy(tab[i], tab[i + 1]);
		i = i + 1;
	}
}