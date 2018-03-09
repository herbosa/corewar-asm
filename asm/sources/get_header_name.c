/*
** EPITECH PROJECT, 2017
** get_header_name.c
** File description:
** get functions for header and name
*/

#include "asm.h"

char *get_name(char *name)
{
	int i = 0;
	int j = 0;

	while (name[i]) {
		if (name[i] == '/')
			j = i + 1;
		i = i + 1;
	}
	if (name[i - 2] == '.' && name[i - 1] == 's') {
		name[i - 2] = '\0';
	} else
		return (NULL);
	name = name + j;
	name = my_strcat(name, 2, ".cor\0");
	return (name);
}

char *get_header_name(char *name, char *s, int i)
{
	int j = 0;

	name = malloc(sizeof(char) * my_strlen(s));
	if (s[i] == '\0')
		return (NULL);
	while (s[i] != '"') {
		i = i + 1;
		if (s[i] == '\0')
			return (NULL);
	}
	i = i + 1;
	while (s[i] != '"') {
		name[j] = s[i];
		i = i + 1;
		j = j + 1;
		if (s[i] == '\0')
			return (NULL);
	}
	name[j] = '\0';
	return (name);
}

char *get_header_comment(char *name, char *s, int i)
{
	int j = 0;

	name = malloc(sizeof(char) * my_strlen(s));
	if (s[i] == '\0')
		return (NULL);
	while (s[i] != '"') {
		i = i + 1;
		if (s[i] == '\0')
			return (NULL);
	}
	i = i + 1;
	while (s[i] != '"') {
		name[j] = s[i];
		i = i + 1;
		j = j + 1;
		if (s[i] == '\0')
			return (NULL);
	}
	name[j] = '\0';
	return (name);
}
