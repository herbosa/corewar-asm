/*
** EPITECH PROJECT, 2018
** my_puterr_nbr.c
** File description:
** my_puterr_nbr.c
*/

#include "str.h"

int my_puterr_nbr(int nb)
{
	char c;

	if (nb > 9)
		my_put_nbr(nb / 10);
	else if (nb < 0) {
		nb = nb * -1;
		write(2, "-", 1);
		my_put_nbr(nb / 10);
	}
	c = nb % 10 + '0';
	write(2, &c, 1);
	return (0);
}