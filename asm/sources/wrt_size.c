/*
** EPITECH PROJECT, 2017
** wrt_size.c
** File description:
** wrt and size functions
*/

#include "asm.h"

wrt_t ***compile_file_2(char ***inst, wrt_t ***wrt_nbr, int i)
{
	if (my_strcmp(inst[i][0], "live\0") == 1)
		cmd_live(inst, wrt_nbr, i);
	if (my_strcmp(inst[i][0], "ld\0") == 1)
		cmd_ld(inst, wrt_nbr, i);
	if (my_strcmp(inst[i][0], "st\0") == 1)
		cmd_st(inst, wrt_nbr, i);
	if (my_strcmp(inst[i][0], "add\0") == 1)
		cmd_add(inst, wrt_nbr, i);
	if (my_strcmp(inst[i][0], "sub\0") == 1)
		cmd_sub(inst, wrt_nbr, i);
	if (my_strcmp(inst[i][0], "and\0") == 1)
		cmd_and(inst, wrt_nbr, i);
	if (my_strcmp(inst[i][0], "or\0") == 1)
		cmd_or(inst, wrt_nbr, i);
	if (my_strcmp(inst[i][0], "xor\0") == 1)
		cmd_xor(inst, wrt_nbr, i);
	if (my_strcmp(inst[i][0], "zjmp\0") == 1)
		cmd_zjmp(inst, wrt_nbr, i);
	return (wrt_nbr);
}

wrt_t ***compile_file(char ***inst, int len)
{
	int i = 0;
	wrt_t ***wrt_nbr = NULL;

	wrt_nbr = fill_wrt_struc(inst, len, wrt_nbr);
	for (i = 0; inst[i]; i = i + 1) {
		wrt_nbr = compile_file_2(inst, wrt_nbr, i);
		if (my_strcmp(inst[i][0], "ldi\0") == 1)
			cmd_ldi(inst, wrt_nbr, i);
		if (my_strcmp(inst[i][0], "sti\0") == 1)
			cmd_sti(inst, wrt_nbr, i);
		if (my_strcmp(inst[i][0], "fork\0") == 1)
			cmd_fork(inst, wrt_nbr, i);
		if (my_strcmp(inst[i][0], "lld\0") == 1)
			cmd_lld(inst, wrt_nbr, i);
		if (my_strcmp(inst[i][0], "lldi\0") == 1)
			cmd_lldi(inst, wrt_nbr, i);
		if (my_strcmp(inst[i][0], "lfork\0") == 1)
			cmd_lfork(inst, wrt_nbr, i);
		if (my_strcmp(inst[i][0], "aff\0") == 1)
			cmd_aff(inst, wrt_nbr, i);
	}
	return (wrt_nbr);
}

int get_progsize(wrt_t ***wrt_nbr)
{
	int res = 0;
	int i = 0;
	int j = 0;

	for (i = 0; wrt_nbr[i]; i = i + 1)
		for (j = 0; wrt_nbr[i][j]; j = j + 1)
			res = res + wrt_nbr[i][j]->size;
	return (res);
}

void write_wrt_nbr(wrt_t ***wrt_nbr, int fd_cor, int i, int j)
{
	if (wrt_nbr[i][j]->nbr >= 0 && wrt_nbr[i][j]->size != 2) {
		if (wrt_nbr[i][j]->size == 1)
			write_nbr_1(wrt_nbr[i][j]->nbr, fd_cor);
		if (wrt_nbr[i][j]->size == 2)
			write_nbr_2(wrt_nbr[i][j]->nbr, fd_cor);
		if (wrt_nbr[i][j]->size == 4)
			write_nbr(wrt_nbr[i][j]->nbr, fd_cor);
	} else
		write_nbr_2((wrt_nbr[i][j]->nbr + 65536), fd_cor);
}

int write_inst(wrt_t ***wrt_nbr, int fd_cor)
{
	int i = 0;
	int j = 0;
	int x = 0;

	for (i = 0; wrt_nbr[i]; i = i + 1) {
		write_wrt_nbr(wrt_nbr, fd_cor, i, 0);
		for (x = 0; wrt_nbr[i][x]; x = x + 1);
		write_wrt_nbr(wrt_nbr, fd_cor, i, x - 1);
		for (j = 1; j < x - 1 && wrt_nbr[i][j]; j = j + 1)
			write_wrt_nbr(wrt_nbr, fd_cor, i, j);
	}
	return (0);
}
