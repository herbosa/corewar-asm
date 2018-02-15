/*
** EPITECH PROJECT, 2018
** my_puterr.c
** File description:
** my_puterr.c
*/

#include "str.h"

void my_puterr(char *str)
{
	write(2, str, my_strlen(str));
}