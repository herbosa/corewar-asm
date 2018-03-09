/*
** EPITECH PROJECT, 2018
** includes.h
** File description:
** includes.h
*/

#ifndef ASM_H_
#define ASM_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include "str.h"
#include "get_next_line.h"
#include "parser.h"

#define COREWAR_EXEC_MAGIC 0xea83f3
#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048

typedef struct header_s {
   int  magic;
   char prog_name[PROG_NAME_LENGTH + 1];
   int  prog_size;
   char comment[COMMENT_LENGTH + 1];
} header_t;

char **tab(char **argsv, char *name);
int my_tablen(char **tab);
int cmd_ldi_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
int cmd_ldi_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_ldi(char ***inst, wrt_t ***wrt_nbr, int i);
int cmd_ld_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_ld(char ***inst, wrt_t ***wrt_nbr, int i);
int convert_param(int param);
int cmd_and_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
int cmd_and_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_and(char ***inst, wrt_t ***wrt_nbr, int i);
int cmd_lldi_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
int cmd_lldi_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_lldi(char ***inst, wrt_t ***wrt_nbr, int i);
int cmd_lld_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_lld(char ***inst, wrt_t ***wrt_nbr, int i);
int cmd_sti_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
int cmd_sti_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_sti(char ***inst, wrt_t ***wrt_nbr, int i);
int write_nbr();
int write_head(int fd_s, int fd_cor, int a);
int write_nbr_2(int nbr, int fd);
int write_nbr_1(int nbr, int fd);
int display_header_err(int bo);
void disp_syntax_err(int nb);
char *my_strcpy();
void check_instr();
int cmd_xor_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
int cmd_xor_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_xor(char ***inst, wrt_t ***wrt_nbr, int i);
int cmd_or_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
int cmd_or_first_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_or(char ***inst, wrt_t ***wrt_nbr, int i);
int cmd_sub_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
			int param);
void cmd_sub(char ***inst, wrt_t ***wrt_nbr, int i);
int cmd_add_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
			int param);
void cmd_add(char ***inst, wrt_t ***wrt_nbr, int i);
int cmd_st_second_param(char ***inst, wrt_t ***wrt_nbr, int i,
				int param);
void cmd_st(char ***inst, wrt_t ***wrt_nbr, int i);
void cmd_fork(char ***inst, wrt_t ***wrt_nbr, int i);
void cmd_lfork(char ***inst, wrt_t ***wrt_nbr, int i);
void cmd_live(char ***inst, wrt_t ***wrt_nbr, int i);
void cmd_zjmp(char ***inst, wrt_t ***wrt_nbr, int i);
void cmd_aff(char ***inst, wrt_t ***wrt_nbr, int i);
void disp_strc(wrt_t ***wrt_nbr);
wrt_t ***compile_file_2(char ***inst, wrt_t ***wrt_nbr, int i);
wrt_t ***compile_file(char ***inst, int len);
int get_progsize(wrt_t ***wrt_nbr);
void write_wrt_nbr(wrt_t ***wrt_nbr, int fd_cor, int i, int j);
int write_inst(wrt_t ***wrt_nbr, int fd_cor);
wrt_t ***fill_wrt_struc(char ***inst, int len, wrt_t ***wrt_nbr);

#endif
