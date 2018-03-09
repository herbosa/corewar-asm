/*
** EPITECH PROJECT, 2017
** label.c
** File description:
** label functions
*/

#include "asm.h"

int get_label_pos(char *label, char ***inst)
{
	int i = 0;

	for (i = 0; inst[i]; i = i + 1)
		if (my_strncmp(label, inst[i][0], my_strlen(label)) == 1 &&
			inst[i][0][my_strlen(label)] == ':')
			return (i);
	my_puterr("Undefined Label :\t");
	my_puterr(label);
	my_puterr("\n");
	exit(84);
}

int get_label_value(wrt_t ***wrt_nbr, int x, int i)
{
	int res = 0;

	if (i < x)
		res = get_progsize_between_two_value(wrt_nbr, i, x);
	else
		res = -1 * (get_progsize_between_two_value(wrt_nbr, x, i - 1));
	return (res);
}

wrt_t ***get_label(char ***inst, wrt_t ***wrt_nbr, int i, int j)
{
	int x = 0;
	int nbr_result = 0;

	if (inst[i][j][0] && inst[i][j][0] == ':') {
		inst[i][j]++;
		x = get_label_pos(inst[i][j], inst);
		nbr_result = get_label_value(wrt_nbr, x, i);
		wrt_nbr[i][j]->nbr = nbr_result;
	}
	return (wrt_nbr);
}

wrt_t ***parse_label(char ***inst, wrt_t ***wrt_nbr)
{
	int i = 0;
	int j = 0;

	for (i = 0; inst[i]; i = i + 1)
		for (j = 0; inst[i][j]; j = j + 1)
			wrt_nbr = get_label(inst, wrt_nbr, i, j);
	return (wrt_nbr);
}

int file_parser(char **file, int fd_s, char *new_name, int fd_cor)
{
	int len = my_tablen(file);
	char ***inst = NULL;
	wrt_t ***wrt_nbr;

	if (len == -1)
		exit(84);
	lseek(fd_s, 0, SEEK_SET);
	inst = code_parser(file, len, inst);
	if (inst == NULL)
		return (84);
	wrt_nbr = compile_file(inst, len);
	wrt_nbr = parse_label(inst, wrt_nbr);
	fd_cor = open(new_name, O_CREAT | O_RDWR, S_IROTH |
		S_IRUSR | S_IRGRP | S_IWUSR | S_IWGRP);
	if (write_head(fd_s, fd_cor, get_progsize(wrt_nbr)) == 84
	|| write_inst(wrt_nbr, fd_cor) == 84)
		return (84);
	return (0);
}
