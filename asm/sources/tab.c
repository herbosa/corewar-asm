/*
** EPITECH PROJECT, 2017
** tab.c
** File description:
** tab functions
*/

#include "asm.h"

char **tab(char **argsv, char *name)
{
	int i = 0;
	int j = 0;
	int k = 0;

	argsv[0] = malloc((my_strlen(name) + 1) * sizeof(char));
	while (name[k] != '\0') {
		if (name[k] == ' ' || name[k] == ',') {
			argsv[j][i] = '\0';
			j = j + 1;
			argsv[j] = malloc((my_strlen(name) + 1) * sizeof(char));
			i = 0;
		} else {
			argsv[j][i] = name[k];
			i = i + 1;
		}
		k = k + 1;
	}
	argsv[j][i] = '\0';
	argsv[j + 1] = '\0';
	return (argsv);
}

int my_tablen(char **tab)
{
	int i = 0;

	if (!tab)
		return (-1);
	while (tab[i])
		i = i + 1;
	return (i);
}

int get_progsize(wrt_t ***wrt_nbr)
{
	int res = 0;
	int i = 0;
	int j = 0;

	for (i = 0; wrt_nbr[i]; i = i + 1)
		for (j = 0; wrt_nbr[i][j]; j = j + 1)
			res = res + wrt_nbr[i][j]->size;
	return (res);
}
