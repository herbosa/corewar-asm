/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "str.h"

char *my_strcat(char *res, char *buf)
{
	char *str;
	int i = 0;
	int j = 0;

	if (res != NULL) {
		str = malloc(sizeof(char) *
		(my_strlen(res) + my_strlen(buf) + 1));
		while (res[i]) {
			str[i] = res[i];
			i = i + 1;
		}
	} else
		str = malloc(sizeof(char) * (my_strlen(buf) + 1));
	while (buf[j]) {
		str[i] = buf[j];
		j = j + 1;
		i = i + 1;
	}
	str[i] = '\0';
	return (str);
}