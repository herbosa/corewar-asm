/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef STR_H_
#define STR_H_

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);
void my_putstr(char *str);
void my_puterr(char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *res, char *buf);
char **my_str_to_word_tab2(char *cmd, char **tab, char c);
int my_atoi(char *str);
int my_str_is_num(char *str);
char *my_cleaner(char *str);
char *check_start_and_end(char *str);
char *check_inside_str(char *str);
char *my_shift_str(char *str, int i);
int my_strcmp(char *str, char *str2);
int my_str_is_alpha(char *str);
void display_tab(char **tab);

#endif
