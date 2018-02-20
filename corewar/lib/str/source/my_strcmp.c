/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "str.h"

int my_strcmp(char *str, char *str2)
{
	int i = 0;

	if (my_strlen(str) != my_strlen(str2))
		return (0);
	while (str[i]) {
		if (str[i] != str2[i])
			return (0);
		i = i + 1;
	}
	return (1);
}