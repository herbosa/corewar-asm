/*
** EPITECH PROJECT, 2018
** cmd_parser.c
** File description:
** cmd_parser.c
*/

#include "asm.h"
#include "parser.h"

int display_header_err(int bo);
void disp_syntax_err(int nb);
char *my_strcpy();

char **tab(char **argsv, char *name)
{
	int i = 0;
	int j = 0;
	int k = 0;

	argsv[0] = malloc((my_strlen(name) + 1) * sizeof(char));
	while (name[k] != '\0') {
		if (name[k] == ' ' || name[k] == ',' ) {
			argsv[j][i] = '\0';
			j = j + 1;
			argsv[j] = malloc((my_strlen(name) + 1) * sizeof(char));
			i = 0;
		} else {
			argsv[j][i] = name[k];
			i = i + 1;
		}
		k = k + 1;
	}
	argsv[j][i] = '\0';
	argsv[j + 1] = '\0';
	return (argsv);
}

int my_tablen(char **tab)
{
	int i = 0;

	while (tab[i])
		i = i + 1;
	return (i);
}

wrt_t ***fill_wrt_struc(char ***inst, int len, wrt_t ***wrt_nbr)
{
	int i = 0;
	int j = 0;

	wrt_nbr = malloc(sizeof(wrt_t **) * (len + 1));
	for (i = 0; inst[i]; i = i + 1) {
		wrt_nbr[i] = malloc(sizeof(wrt_t *) * (len + 1));
		for (j = 0; inst[i][j]; j = j + 1) {
			wrt_nbr[i][j] = malloc(sizeof(wrt_t *) * 1);
			wrt_nbr[i][j]->nbr = 0;
			wrt_nbr[i][j]->size = 0;
		}
		wrt_nbr[i][j] = malloc(sizeof(wrt_t *) * 1);
		wrt_nbr[i][j]->nbr = 0;
		wrt_nbr[i][j]->size = 0;
		wrt_nbr[i][j + 1] = NULL;
	}
	wrt_nbr[i] = NULL;
	return (wrt_nbr);
}

char ***code_parser(char **file, int len, char ***inst)
{
	int i = 0;

	inst = malloc(sizeof(char ***) * (len * 5));
	if (inst == NULL)
		return (NULL);
	for (i = 0; i < my_tablen(file); i = i + 1) {
		inst[i] = malloc(sizeof(char **) * (len * 4));
		if (inst[i] == NULL)
			return (NULL);
		inst[i] = tab(inst[i], file[i]);
	}
	inst[i] = NULL;
	return (inst);
}

int my_uint_len(int nb)
{
	int i = 0;

	while (nb != 0) {
		nb = nb / 10;
		i = i + 1;
	}
	return (i);
}

int my_ten_pow(int n)
{
	int i = 0;
	int res = 1;

	if (n == 0)
		return (1);
	for (i = 0; i < n; i = i + 1)
		res = res * 10;
	return (res);
}

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


int cmd_ldi_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
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
		wrt_nbr[i][2]->size = 2;
		param = param + 1000;
	} else {
		my_puterr("invalid comand in ldi");
		exit(84);
	}
	return (param);
}

int cmd_ldi_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	wrt_nbr[i][0]->nbr = 10;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 10000;
	} else if (my_strncmp(inst[i][1], "%", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
		param = param + 100000;
	} else {
		if (my_str_is_num(inst[i][1]) == 1)
			wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
		param = param + 110000;
	}
	return (param);
}

void cmd_ldi(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	param = cmd_ldi_first_param(inst, wrt_nbr, i, param);
	param = cmd_ldi_second_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 1;
	} else {
		my_puterr("invalid instruction in ldi");
		exit(84);
	}
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}

int cmd_lldi_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
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
		wrt_nbr[i][2]->size = 2;
		param = param + 1000;
	} else {
		my_puterr("invalid comand in ldi");
		exit(84);
	}
	return (param);
}

int cmd_lldi_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	wrt_nbr[i][0]->nbr = 14;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 10000;
	} else if (my_strncmp(inst[i][1], "%", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
		param = param + 100000;
	} else {
		if (my_str_is_num(inst[i][1]) == 1)
			wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
		param = param + 110000;
	}
	return (param);
}

void cmd_lldi(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	param = cmd_lldi_first_param(inst, wrt_nbr, i, param);
	param = cmd_lldi_second_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 1;
	} else {
		my_puterr("invalid instruction in lldi");
		exit(84);
	}
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}

int cmd_sti_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
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
		wrt_nbr[i][2]->size = 2;
		param = param + 1000;
	} else {
		if (my_str_is_num(inst[i][2]) == 1)
			wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 2;
		param = param + 1100;
	}
	return (param);
}

int cmd_sti_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	wrt_nbr[i][0]->nbr = 11;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = 10000;
	} else {
		my_puterr("invalid instruction in sti");
		exit(84);
	}
	return (param);
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

int cmd_xor_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
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

int cmd_xor_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	wrt_nbr[i][0]->nbr = 8;
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

void cmd_xor(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	param = cmd_xor_first_param(inst, wrt_nbr, i, param);
	param = cmd_xor_second_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 1;
	} else {
		my_puterr("invalid instruction in xor");
		exit(84);
	}
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}

int cmd_or_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
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

int cmd_or_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	wrt_nbr[i][0]->nbr = 7;
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

void cmd_or(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	param = cmd_or_first_param(inst, wrt_nbr, i, param);
	param = cmd_or_second_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 1;
	} else {
		my_puterr("invalid instruction in or");
		exit(84);
	}
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}

void cmd_sti(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	param = cmd_sti_first_param(inst, wrt_nbr, i, param);
	param = cmd_sti_second_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 1;
	} else if (my_strncmp(inst[i][3], "%", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 2;
		param = param + 10;
	} else {
		my_puterr("invalid instruction in sti");
		exit(84);
	}
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}

int cmd_ld_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 100;
	} else if (my_strncmp(inst[i][1], "%", 1) == 1) {
		my_puterr("invalid instruction in ld");
		exit(84);
	} else {
		if (my_str_is_num(inst[i][1]) == 1)
			wrt_nbr[i][1]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][1]->size = 2;
		param = param + 1100;
	}
	return (param);
}

void cmd_ld(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	wrt_nbr[i][0]->nbr = 2;
	wrt_nbr[i][0]->size = 1;
	param = cmd_ld_first_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][2]->size = 2;
		param = param + 10000;
	} else {
		my_puterr("invalid instruction in ld");
		exit(84);
	}
	wrt_nbr[i][3]->nbr = convert_param(param);
	wrt_nbr[i][3]->size = 1;
}

int cmd_lld_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = param + 100;
	} else if (my_strncmp(inst[i][1], "%", 1) == 1) {
		my_puterr("invalid instruction in ld");
		exit(84);
	} else {
		if (my_str_is_num(inst[i][1]) == 1)
			wrt_nbr[i][1]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][1]->size = 2;
		param = param + 1100;
	}
	return (param);
}

void cmd_lld(char ***inst, wrt_t ***wrt_nbr, int i)
{
	int param = 0;

	wrt_nbr[i][0]->nbr = 13;
	wrt_nbr[i][0]->size = 1;
	param = cmd_ld_first_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][2]->size = 2;
		param = param + 10000;
	} else {
		my_puterr("invalid instruction in lld");
		exit(84);
	}
	wrt_nbr[i][3]->nbr = convert_param(param);
	wrt_nbr[i][3]->size = 1;
}

int cmd_sub_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
			int param)
{
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 2;
		param = param + 100;
	} else {
		my_puterr("invalid instruction in sub");
		exit(84);
	}
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 2;
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
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
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
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 2;
		param = param + 100;
	} else {
		my_puterr("invalid instruction in add");
		exit(84);
	}
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 2;
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
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
		param = param + 10000;
	} else {
		my_puterr("invalid instruction in add");
		exit(84);
	}
	param = cmd_add_second_param(inst, wrt_nbr, i, param);
	wrt_nbr[i][4]->nbr = convert_param(param);
	wrt_nbr[i][4]->size = 1;
}

int cmd_st_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param)
{
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		inst[i][2]++;
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 1;
		param = param + 10000;
	} else if (my_strncmp(inst[i][2], "%", 1) == 1) {
		my_puterr("invalid instruction in st");
		exit(84);
	} else {
		if (my_str_is_num(inst[i][2]) == 1)
			wrt_nbr[i][2]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
		param = param + 110000;
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

void cmd_fork(char ***inst, wrt_t ***wrt_nbr, int i)
{
	wrt_nbr[i][0]->nbr = 1;
	wrt_nbr[i][0]->size = 12;
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
	wrt_nbr[i][0]->nbr = 1;
	wrt_nbr[i][0]->size = 15;
	if (my_strncmp(inst[i][1], "%", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 2;
	} else {
		my_puterr("invalid instruction in lfork");
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
	wrt_nbr[i][0]->nbr = 16;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
	} else {
		my_puterr("invalid instruction in aff");
		exit(84);
	}
}

void disp_strc(wrt_t ***wrt_nbr) {
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

wrt_t*** compile_file(char ***inst, int len)
{
	int i = 0;
	wrt_t ***wrt_nbr = NULL;

	wrt_nbr = fill_wrt_struc(inst, len, wrt_nbr);
	for (i = 0; inst[i]; i = i + 1) {
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
			cmd_fork(inst, wrt_nbr, i);
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
		for (j = 0; wrt_nbr[i][j]; j = j + 1) {
			res = res + wrt_nbr[i][j]->size;
		}
	return (res);
}

void write_wrt_nbr(wrt_t ***wrt_nbr, int fd_cor, int i, int j)
{
	if (wrt_nbr[i][j]->size == 1)
		write_nbr_1(wrt_nbr[i][j]->nbr, fd_cor);
	if (wrt_nbr[i][j]->size == 2)
		write_nbr_2(wrt_nbr[i][j]->nbr, fd_cor);
	if (wrt_nbr[i][j]->size == 4)
		write_nbr(wrt_nbr[i][j]->nbr, fd_cor);
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
	return(0);
}

int file_parser(char **file, int fd_s, int fd_cor)
{
	int len = my_tablen(file);
	char ***inst = NULL;
	wrt_t ***wrt_nbr;

	lseek(fd_s, 0, SEEK_SET);
	while (file[0][0] == '#')
		file++;
	while (file[0] && (file[0][0] == '#' || file[0][0] == '.' || file[0][0] == '\0'))
		file++;
	inst = code_parser(file, len, inst);
	if (inst == NULL)
		return (84);
	wrt_nbr = compile_file(inst, len);
	if (write_head(fd_s, fd_cor, get_progsize(wrt_nbr)) == 84)
                return (84);
	if (write_inst(wrt_nbr, fd_cor) == 84)
                return (84);
	return (0);
}
