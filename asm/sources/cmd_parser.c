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
