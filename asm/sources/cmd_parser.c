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
		return (display_header_err(0));
	if (!my_strncmp(file[1], ".comment ", 9))
		return (display_header_err(1));
	ret = code_parser(file, code);
	if (ret > 0) {
		disp_syntax_err(ret);
		return (84);
	}
	return (0);
}

int code_parser(char **file, op_t **code)
{
	int y = 3;
	int x = 0;
	int ret = check_label(file, y);

	if (ret == 84)
		return (y);
	code[0] = malloc(sizeof(op_t*) * my_tablen(file));
	while (check_label(file, y) == 0) {
		code[0][x] = cmd_parser();
		y = y + 1;
		x = x + 1;
	}
	get_labels(file, y, code);
	return (0);
}

void get_labels(char **file, int y, op_t **code)
{
	int x = 0;
	int z = 0;
	op_t op_tab[] = fill_op_tab();

	while (file[y]) {
		if (check_label(file[y]) == 1) {
			z = z + 1;
			x = 0;
		}
		code[z][x] = cmd_parser(file[y], op_tab);
		y = y + 1;
		x = x + 1;
	}
}

op_t cmd_parser(char *str, op_t op_tab[])
{
	op_t cmd;
	char *label = malloc(sizeof(char) * my_strlen(str));

	if (check_label(str) == 1) {
		while (str[i] != ':') {
			label[i] = str[i];
			i = i + 1;
		}
	}
}

int check_label(char *str)
{
	int x = 0;

	while (my_is_in_str(LABEL_CHARS, str[x]))
		x = x + 1;
	if (!str[x])
		return (84);
	if (str[x] == ' ')
		return (0);
	else if (str[x] == ':')
		return (1);
	else
		return (84);
}