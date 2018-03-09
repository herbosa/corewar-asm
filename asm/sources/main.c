/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** corewar
*/

#include "asm.h"

int main(int argc, char **argv)
{
	int fd_s = 0;
	int fd_cor = 0;
	char *new_name;

	if (argc != 2)
		return (84);
	fd_s = open(argv[1], O_RDONLY);
	if (fd_s == -1)
		return (84);
	new_name = get_name(argv[1]);
	if (new_name == NULL)
		return (84);
	return (file_parser(file_to_tab(fd_s), fd_s, new_name, fd_cor));
}
