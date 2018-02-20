/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "virtual.h"

void helper(void)
{
	my_printf("USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number] [-a");
	my_printf(" load_address] prog_name] ...\n\nDESCRIPTION\n\t");
	my_printf("-dump nbr_cycle\tdumps the memory after the nbr_cycle");
	my_printf(" execution (if the round isn’t\n\t\t\talready over) with the");
	my_printf(" following format: 32 bytes/line in\n\t\t\thexadecimal");
	my_printf(" A0BCDEFE1DD3...)\n\t-n prog_number\tsets the next");
	my_printf(" program’s number. By default, the first free number\n\t\t\t");
	my_printf("in the parameter order\n\t-a load_address\tsets the");
	my_printf(" next program’s loading address. When no address is\n\t\t\t");
	my_printf("specified, optimize the addresses so that the processes");
	my_printf(" are as far\n\t\t\taway from each other as possible. ");
	my_printf("The addresses are MEM_SIZE modulo\n");
}

int main(int argc, char **argv)
{
	if (argc == 2 && my_strcmp(argv[1], "-h") && argv[1][2] == '\0') {
		helper();
		return (0);
	}
	return (0);
}
