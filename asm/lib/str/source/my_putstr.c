/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "str.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}