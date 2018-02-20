/*
** EPITECH PROJECT, 2018
** my_display_tab.c
** File description:
** my_display_tab.c
*/

#include "str.h"

void display_tab(char **tab)
{
	int i = 0;

	while (tab[i]) {
		my_putstr(tab[i]);
		my_putchar('\n');
		i = i + 1;
	}
}