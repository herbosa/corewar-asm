/*
** EPITECH PROJECT, 2018
** my_str_is_alpha.c
** File description:
** my_str_is_alpha.c
*/

#include "str.h"

int my_str_is_alpha(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i]) {
		if ((str[i] >= 'A' && str[i] <= 'Z') ||
		(str[i] >= 'a' && str[i] <= 'z'))
			count = count + 1;
		i = i + 1;
	}
	if (count == my_strlen(str))
		return (1);
	else
		return (0);
}