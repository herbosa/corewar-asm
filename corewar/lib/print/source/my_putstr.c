/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** function that displays, one-by-one, the characters of a string.
*/

#include <unistd.h>
#include "stdyo.h"

int my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
	return (0);
}
