/*
** EPITECH PROJECT, 2017
** cmd_sub_add.c
** File description:
** cmd function for sub and add
*/

#include "asm.h"

int cmd_sub_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
			int param)
{
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		inst[i][2]++;
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 1;
		param = param + 100;
	} else {
		my_puterr("invalid instruction in sub");
		exit(84);
	}
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 1;
	} else {
		my_puterr("invalid instruction in sub");
		exit(84);
	}
	return (param);
}

void cmd_sub(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	wrt_nbr[i][0]->nbr = 5;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 10000;
	} else {
		my_puterr("invalid instruction in sub");
		exit(84);
	}
	param = cmd_sub_second_param(inst, wrt_nbr, i, param);
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}

int cmd_add_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
			int param)
{
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		inst[i][2]++;
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 1;
		param = param + 100;
	} else {
		my_puterr("invalid instruction in add");
		exit(84);
	}
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 1;
	} else {
		my_puterr("invalid instruction in add");
		exit(84);
	}
	return (param);
}

void cmd_add(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	wrt_nbr[i][0]->nbr = 4;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 10000;
	} else {
		my_puterr("invalid instruction in add");
		exit(84);
	}
	param = cmd_add_second_param(inst, wrt_nbr, i, param);
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}
