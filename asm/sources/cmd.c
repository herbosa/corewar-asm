/*
** EPITECH PROJECT, 2017
** cmd.c
** File description:
** cmd functions
*/

#include "asm.h"

void cmd_live(char ***inst, wrt_t ***wrt_nbr, int i)
{
	wrt_nbr[i][0]->nbr = 1;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "%", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 4;
	} else {
		my_puterr("invalid instruction in live");
		exit(84);
	}
}

void cmd_zjmp(char ***inst, wrt_t ***wrt_nbr, int i)
{
	wrt_nbr[i][0]->nbr = 9;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "%", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
	} else {
		my_puterr("invalid instruction in zjmp");
		exit(84);
	}
}

void cmd_aff(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	wrt_nbr[i][0]->nbr = 16;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 10000;
	} else {
		my_puterr("invalid instruction in aff");
		exit(84);
	}
	wrt_nbr[i][2]->nbr = convert_param(param);
	wrt_nbr[i][2]->size = 1;
}

void disp_strc(wrt_t ***wrt_nbr)
{
	int j = 0;
	int i = 0;
	for (i = 0; wrt_nbr[i]; i = i + 1) {
	for (j = 0; wrt_nbr[i][j]; j = j + 1) {
		my_putstr("nbr");
		my_put_nbr(wrt_nbr[i][j]->nbr);
		my_putstr("size");
		my_put_nbr(wrt_nbr[i][j]->size);
		my_putstr("\n");
	}my_putstr("\n");}
}
