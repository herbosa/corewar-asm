/*
** EPITECH PROJECT, 2018
** my_is_in_str.c
** File description:
** my_is_in_str.c
*/

#include "str.h"

int my_is_in_str(char *str, char c)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == c)
			return (1);
		i = i + 1;
	}
	return (0);
}