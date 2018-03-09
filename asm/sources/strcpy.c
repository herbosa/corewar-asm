/*
** EPITECH PROJECT, 2017
** strcpy.c
** File description:
** str copy functions
*/

#include "asm.h"

char *my_strncpy(char *dest, char const *src, int i)
{
	int j = 0;

	while (j < i && src[j]) {
		dest[j] = src[j];
		j = j + 1;
	}
	dest[j] = 0;
	return (dest);
}

char *my_strndup(char *str, int i)
{
	char *s = malloc(sizeof(char) * my_strlen(str) + 2);

	if (s == 0)
		return (0);
	my_strncpy(s, str, i);
	return (s);
}

char *my_strcpy(char *dest, char const *src)
{
	int j = 0;

	while (src[j]) {
		dest[j] = src[j];
		j = j + 1;
	}
	dest[j] = 0;
	return (dest);
}

char *my_strdup(char *str)
{
	char *s = malloc(sizeof(char) * my_strlen(str) + 2);

	if (s == 0)
		return (0);
	my_strcpy(s, str);
	return (s);
}
