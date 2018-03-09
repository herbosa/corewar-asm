/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "virtual.h"

int my_strcmp(char *str2, char *str)
{
	int i = 0;

	if (my_strlen(str) != my_strlen(str2))
		return (0);
	while (str[i]) {
		if (str[i] != str2[i])
			return (0);
		i = i + 1;
	}
	return (1);
}

int my_strlen(char *str)
{
	int i = 0;

	for (i = 0; str[i]; i = i + 1);
	return (i);
}

void my_putstr(char *s)
{
	write(1, s, my_strlen(s));
}

void helper(void)
{
	my_putstr("USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number] [-a");
	my_putstr(" load_address] prog_name] ...\n\nDESCRIPTION\n\t");
	my_putstr("-dump nbr_cycle\tdumps the memory after the nbr_cycle");
	my_putstr(" execution (if the round isn’t\n\t\t\talready over) with ");
	my_putstr("the following format: 32 bytes/line in\n\t\t\thexadecimal");
	my_putstr(" A0BCDEFE1DD3...)\n\t-n prog_number\tsets the next");
	my_putstr(" program’s number. By default, the first free number\n\t\t");
	my_putstr("\tin the parameter order\n\t-a load_address\tsets the");
	my_putstr(" next program’s loading address. When no address is\n\t\t");
	my_putstr("\tspecified, optimize the addresses so that the processes");
	my_putstr(" are as far\n\t\t\taway from each other as possible. ");
	my_putstr("The addresses are MEM_SIZE modulo\n");
}

int main(int argc, char **argv)
{
	if (argc == 2 && my_strcmp(argv[1], "-h") && argv[1][2] == '\0') {
		helper();
		return (0);
	}
	return (0);
}
