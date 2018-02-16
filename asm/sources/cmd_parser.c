/*
** EPITECH PROJECT, 2018
** cmd_parser.c
** File description:
** cmd_parser.c
*/

#include "asm.h"

int file_parser(char **file, op_t **code)
{
	int i = 0;
	int ret = 0;

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
	ret = code_parser(file, code);
	return (ret);
}

int code_parser(char **file, op_t **code)
{
	op_t op_tab[] = fill_op_tab()
	int y = 3;
	int x = 0;
	int ret = check_label(file, y);

	if (ret == 84)
		return (84);
	while (check_label(file, y) == 0) {
		code[0][x] = cmd_parser();
		x = x + 1;
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

int check_label(char **file, int y)
{
	int x = 0;

	while (my_is_in_str(LABEL_CHARS, file[y][x]))
		x = x + 1;
	if (!file[y][x])
		return (84);
	if (file[y][x] == ' ')
		return (0);
	else if (file[y][x] == ':')
		return (1);
	else
		return (84);
}