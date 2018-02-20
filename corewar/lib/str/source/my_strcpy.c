/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "str.h"

char *my_strcpy(char *dest, char const *src)
{
	int count_1 = 0;

	while (src[count_1] != '\0') {
		dest[count_1] = src[count_1];
		count_1 = count_1 + 1;
	}
	dest[count_1] = '\0';
	return (dest);
}