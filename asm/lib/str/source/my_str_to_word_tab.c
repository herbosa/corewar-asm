/*
** EPITECH PROJECT, 2018
** my_str_to_word_tab.c
** File description:
** my_str_to_word_tab.c
*/

#include "str.h"

char **my_str_to_word_tab(char *cmd, char c)
{
	char **tab = malloc(sizeof(char*) * my_strlen(cmd));

	cmd = my_cleaner(cmd);
	tab[0] = malloc(sizeof(char) * my_strlen(cmd));
	while (cmd[0] == ' ' && cmd[0] != '\0')
		cmd = cmd + 1;
	my_str_to_word_tab2(cmd, tab, c);
	return (tab);
}

char **my_str_to_word_tab2(char *cmd, char **tab, char c)
{
	int i = 0;
	int x = 0;
	int y = 0;

	while (cmd[i]) {
		tab[y][x] = cmd[i];
		i = i + 1;
		x = x + 1;
		if (cmd[i] == c && cmd[i + 1] != '\0') {
			i = i + 1;
			y = y + 1;
			x = 0;
			tab[y] = malloc(sizeof(char) * my_strlen(cmd));
		}
	}
	y = y + 1;
	tab[y] = NULL;
	return (tab);
}