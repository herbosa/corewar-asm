/*
** EPITECH PROJECT, 2018
** my_tablen.c
** File description:
** my_tablen.c
*/

int my_tablen(char **tab)
{
	int i = 0;

	while (tab[i])
		i = i + 1;
	return (i);
}