/*
** EPITECH PROJECT, 2018
** shift_tab.c
** File description:
** shift_tab.c
*/

#include "str.h"

void shift_tab(char **tab, int i)
{
	while (tab[i + 1]) {
		tab[i] = malloc(sizeof(char *) * (my_strlen(tab[i + 1]) + 1));
		tab[i] = my_strcpy(tab[i], tab[i + 1]);
		i = i + 1;
	}
	tab[i] = '\0';
}
