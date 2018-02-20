/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** my_revstr.c
*/

#include "str.h"

char *my_revstr(char *str)
{
	char c;
	int j = my_strlen(str) - 1;
	int i = 0;

	while (i < j) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		j = j - 1;
		i = i + 1;
	}
	return (str);
}