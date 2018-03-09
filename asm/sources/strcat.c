/*
** EPITECH PROJECT, 2017
** strcat.c
** File description:
** strcat functions
*/

#include "asm.h"

char *my_concat(char *src, char *dest, int j)
{
	int i = 0;

	while (src[i]) {
		dest[j + i] = src[i];
		i = i + 1;
	}
	dest[j + i] = '\0';
	return (dest);
}

char *my_strcat(char *str, int nblist, ...)
{
	va_list listarg;
	char *src;
	char *dest;
	int j;

	va_start(listarg, nblist);
	while (nblist != 1) {
		src = my_strdup(va_arg(listarg, char *));
		j = my_strlen(str);
		dest = malloc(sizeof(char) * (j + 2) * my_strlen(src));
		dest = my_strcpy(dest, str);
		dest = my_concat(src, dest, j);
		nblist = nblist - 1;
		str = my_strdup(dest);
	}
	va_end(listarg);
	return (dest);
}
