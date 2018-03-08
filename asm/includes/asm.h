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
#include "op.h"
#include "get_next_line.h"

int write_nbr();
int write_head(int fd_s, int fd_cor, int a);
int write_nbr_2(int nbr, int fd);
int write_nbr_1(int nbr, int fd);
int display_header_err(int bo);
void disp_syntax_err(int nb);
char *my_strcpy();
void check_instr();

#endif
