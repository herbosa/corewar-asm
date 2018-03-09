/*
** EPITECH PROJECT, 2017
** cmd_st_fork.c
** File description:
** cmd functions for st and fork
*/

#include "asm.h"

int cmd_st_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		inst[i][2]++;
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 1;
		param = param + 100;
	} else if (my_strncmp(inst[i][2], "%", 1) == 1) {
		my_puterr("invalid instruction in st");
		exit(84);
	} else {
		if (my_str_is_num(inst[i][2]) == 1)
			wrt_nbr[i][2]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
		param = param + 1100;
	}
	return (param);
}

void cmd_st(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	wrt_nbr[i][0]->nbr = 3;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 10000;
	} else {
		my_puterr("invalid instruction in st");
		exit(84);
	}
	param = cmd_st_second_param(inst, wrt_nbr, i, param);
	wrt_nbr[i][3]->nbr = convert_param(param);
	wrt_nbr[i][3]->size = 1;
}

void cmd_fork(char ***inst, wrt_t ***wrt_nbr, int i)
{
	wrt_nbr[i][0]->nbr = 12;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "%", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
	} else {
		my_puterr("invalid instruction in fork");
		exit(84);
	}
}

void cmd_lfork(char ***inst, wrt_t ***wrt_nbr, int i)
{
	wrt_nbr[i][0]->nbr = 15;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "%", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
	} else {
		my_puterr("invalid instruction in lfork");
		exit(84);
	}
}
