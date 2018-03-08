/*
** EPITECH PROJECT, 2018
** my_cleaner.C
** File description:
** my_cleaner.C
*/

#include "str.h"

char *my_cleaner(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == '\t')
			str[i] = ' ';
		i = i + 1;
	}
	str = check_start_and_end(str);
	str = check_inside_str(str);
	for (i = 0; str[i]; i = i + 1)
		if (str[i] == ' ' && str[i - 1] == ',')
			str = my_shift_str(str, i);
	return (str);
}

char *check_start_and_end(char *str)
{
	int i = 0;

	while (str[0] && str[0] == ' ')
		str = str + 1;
	i = my_strlen(str) - 1;
	while (i >= 0 && str[i] == ' ') {
		str[i] = '\0';
		i = i - 1;
	}
	return (str);
}

char *check_inside_str(char *str)
{
	int i = 0;

	while (str[i]) {
		while (str[i] == ' ' &&
		(str[i + 1] == ' ' || str[i + 1] == '\0') && str[i + 1])
			str = my_shift_str(str, i);
		i = i + 1;
	}
	return (str);
}

char *my_shift_str(char *str, int i)
{
	while (str[i + 1]) {
		str[i] = str[i + 1];
		i = i + 1;
	}
	str[i] = '\0';
	return (str);
}
