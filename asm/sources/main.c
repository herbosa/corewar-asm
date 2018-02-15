/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** corewar
*/

#include "asm.h"

int main(int argc, char **argv)
{
	int fd = 0;

	if (argc != 2)
		return (84);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (84);
	return (0);
}
