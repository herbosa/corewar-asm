/*
** EPITECH PROJECT, 2018
** my_str_is_num.c
** File description:
** my_str_is_num.c
*/

#include "str.h"

int my_str_is_num(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i = i + 1;
	while (str[i]) {
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i = i + 1;
	}
	return (1);
}