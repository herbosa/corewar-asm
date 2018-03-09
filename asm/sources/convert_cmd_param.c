/*
** EPITECH PROJECT, 2017
** convert_cmd_param.c
** File description:
** convert and cmd parameters functions
*/

#include "asm.h"

int convert_param(int param)
{
	int i = 0;
	int res = 0;

	param = param * 100;
	for (i = 0; param != 0; i = i + 1) {
		res = res + ((param % 10) * (1 << i));
		param = param / 10;
	}
	return (res);
}

int cmd_and_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		inst[i][2]++;
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 1;
		param = param + 100;
	} else if (my_strncmp(inst[i][2], "%", 1) == 1) {
		inst[i][2]++;
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 4;
		param = param + 1000;
	} else {
		if (my_str_is_num(inst[i][2]) == 1)
			wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 2;
		param = param + 1100;
	}
	return (param);
}

int cmd_and_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	wrt_nbr[i][0]->nbr = 6;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 10000;
	} else if (my_strncmp(inst[i][1], "%", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 4;
		param = param + 100000;
	} else {
		if (my_str_is_num(inst[i][1]) == 1)
			wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
		param = param + 110000;
	}
	return (param);
}

void cmd_and(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	param = cmd_and_first_param(inst, wrt_nbr, i, param);
	param = cmd_and_second_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 1;
	} else {
		my_puterr("invalid instruction in and");
		exit(84);
	}
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}
