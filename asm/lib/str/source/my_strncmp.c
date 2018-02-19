/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include "str.h"

int my_strncmp(char *str1, char *str2, int nb)
{
	int i = 0;

	if (my_strlen(str1) < nb || my_strlen(str1) < nb)
		return (0);
	while (i < nb) {
		if (str1[i] != str2[i])
			return (0);
		i = i + 1;
	}
	return (1);
}
