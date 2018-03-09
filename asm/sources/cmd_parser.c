/*
** EPITECH PROJECT, 2018
** cmd_parser.c
** File description:
** cmd_parser.c
*/

#include "asm.h"

wrt_t ***fill_wrt_struc(char ***inst, int len, wrt_t ***wrt_nbr)
{
	int i = 0;
	int j = 0;

	wrt_nbr = malloc(sizeof(wrt_t **) * (len + 1));
	for (i = 0; inst[i]; i = i + 1) {
		wrt_nbr[i] = malloc(sizeof(wrt_t *) * (len + 1));
		for (j = 0; inst[i][j]; j = j + 1) {
			wrt_nbr[i][j] = malloc(sizeof(wrt_t *) * 1);
			wrt_nbr[i][j]->nbr = 0;
			wrt_nbr[i][j]->size = 0;
		}
		wrt_nbr[i][j] = malloc(sizeof(wrt_t *) * 1);
		wrt_nbr[i][j]->nbr = 0;
		wrt_nbr[i][j]->size = 0;
		wrt_nbr[i][j + 1] = NULL;
	}
	wrt_nbr[i] = NULL;
	return (wrt_nbr);
}

char ***code_parser(char **file, int len, char ***inst)
{
	int i = 0;

	inst = malloc(sizeof(char ***) * (len * 5));
	if (inst == NULL)
		return (NULL);
	for (i = 0; i < my_tablen(file); i = i + 1) {
		inst[i] = malloc(sizeof(char **) * (len * 4));
		if (inst[i] == NULL)
			return (NULL);
		inst[i] = tab(inst[i], file[i]);
	}
	inst[i] = NULL;
	return (inst);
}

int my_uint_len(int nb)
{
	int i = 0;

	while (nb != 0) {
		nb = nb / 10;
		i = i + 1;
	}
	return (i);
}

int my_ten_pow(int n)
{
	int i = 0;
	int res = 1;

	if (n == 0)
		return (1);
	for (i = 0; i < n; i = i + 1)
		res = res * 10;
	return (res);
}

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

int get_progsize_between_two_value(wrt_t ***wrt_nbr, int x, int y)
{
	int res = 0;
	int i = 0;
	int j = 0;

	for (i = x; wrt_nbr[i] && i <= y; i = i + 1)
		for (j = 0; wrt_nbr[i][j]; j = j + 1) {
			res = res + wrt_nbr[i][j]->size;
		}
	return (res);
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
	while (file[0] && (file[0][0] == '#' || file[0][0] == '.' || file[0][0] == '\0'))
		file++;
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
