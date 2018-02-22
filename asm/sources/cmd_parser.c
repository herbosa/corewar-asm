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

int cmd_sti_second_param(char ***inst, wrt_t ***wrt_nbr, int i, int param)
{
	if (my_strncmp(inst[i][2], "r", 1) == 1) {
		inst[i][2]++;
		wrt_nbr[i][2]->nbr = my_atoi(inst[i][2]);
		wrt_nbr[i][2]->size = 1;
		param = param + 0100;
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

int cmd_sti_first_param(char ***inst, wrt_t ***wrt_nbr, int i, int param)
{
	wrt_nbr[i][0]->nbr = 11;
	wrt_nbr[i][0]->size = 1;
	if (my_strncmp(inst[i][1], "r", 1) == 1) {
		inst[i][1]++;
		wrt_nbr[i][1]->nbr = my_atoi(inst[i][1]);
		wrt_nbr[i][1]->size = 1;
		param = 010000;
	} else {
		my_puterr("invalid instruction in sti");
		exit(84);
	}
	return (param);
}

void cmd_sti(char ***inst, wrt_t ***wrt_nbr, int i)
{
	unsigned long param = 0;

	param = cmd_sti_first_param(inst, wrt_nbr, i, param);
	param = cmd_sti_second_param(inst, wrt_nbr, i, param);
	if (my_strncmp(inst[i][3], "r", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 1;
		param = param + 01;
	} else if (my_strncmp(inst[i][3], "%", 1) == 1) {
		inst[i][3]++;
		wrt_nbr[i][3]->nbr = my_atoi(inst[i][3]);
		wrt_nbr[i][3]->size = 2;
		param = param + 10;
	} else {
		my_puterr("invalid instruction in sti");
		exit(84);
	}
}

void disp_strc(wrt_t ***wrt_nbr) {
	int j = 0;
	int i = 0;
	for (i = 0; wrt_nbr[i]; i = i + 1)
	for (j = 0; wrt_nbr[i][j]; j = j + 1) {
		my_putstr("nbr");
		my_put_nbr(wrt_nbr[i][j]->nbr);
	        my_putstr("size"); 
		my_put_nbr(wrt_nbr[i][j]->size);
		my_putstr("\n");
	}
}

void compile_file(char ***inst, int len)
{
	int i = 0;
	int j = 0;
	wrt_t ***wrt_nbr = NULL;

	wrt_nbr = fill_wrt_struc(inst, len, wrt_nbr);
// DEBUG
	for (i = 0; inst[i]; i = i + 1)
		for (j = 0; inst[i][j]; j = j + 1) {
			my_putstr(inst[i][j]);
			my_put_nbr(wrt_nbr[i][j]->nbr);
		}
// DEBUG_END
	for (i = 0; inst[i]; i = i + 1) {
		if (my_strcmp(inst[i][0], "sti\0") == 1)
			cmd_sti(inst, wrt_nbr, i);
	}
	disp_strc(wrt_nbr);
}

int file_parser(char **file)
{
	int len = my_tablen(file);
	char ***inst = NULL;

	while (file[0][0] == '#')
		file++;
	if (!my_strncmp(file[0], ".name ", 6))
		return (display_header_err(0));
	if (!my_strncmp(file[1], ".comment ", 9))
		return (display_header_err(1));
	while (file[0][0] == '#' || file[0][0] == '.' || file[0][0] == '\0')
		file++;
	inst = code_parser(file, len, inst);
	if (inst == NULL)
		return (84);
	compile_file(inst, len);
	return (0);
}
