/*
** EPITECH PROJECT, 2018
** my_atoi.c
** File description:
** my_atoi.c
*/

#include "str.h"

int my_atoi(char *str)
{
	int i = 0;
	int res = 0;

	if (str[i] == '-')
		i = i + 1;
	while (str[i]) {
		res = res + str[i] - 48;
		if (str[i + 1])
			res = res * 10;
		i = i + 1;
	}
	if (str[0] == '-')
		return (res * -1);
	return (res);
}