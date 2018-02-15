/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "asm.h"
                       
int write_nbr(int nbr, int fd)
{
	int wrt = 0;
	int mem = nbr;

	nbr = mem / 256 / 256 / 256;
       	wrt = write(fd, &nbr, 1);
	if (wrt == -1)
                return (-1);
	nbr = mem / 256 / 256;
       	wrt = write(fd, &nbr, 1);
	if (wrt == -1)
                return (-1);
	nbr = mem / 256;
       	wrt = write(fd, &nbr, 1);
	if (wrt == -1)
                return (-1);
	nbr = mem;
	wrt = write(fd, &nbr, 1);
	if (wrt == -1)
                return (-1);
	return (0);
}
