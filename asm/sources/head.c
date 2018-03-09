/*
** EPITECH PROJECT, 2017
** head.c
** File description:
** head functions
*/

#include "asm.h"

void fill_head_name(char *name, header_t *head)
{
	int i = 0;

	for (i = 0; i <= PROG_NAME_LENGTH; i = i + 1)
		head->prog_name[i] = '\0';
	for (i = 0; name[i]; i = i + 1)
		head->prog_name[i] = name[i];
}

void fill_head_comment(char *name, header_t *head)
{
	int i = 0;

	for (i = 0; i <= COMMENT_LENGTH; i = i + 1)
		head->comment[i] = '\0';
	for (i = 0; name[i]; i = i + 1)
		head->comment[i] = name[i];
}

int fill_header(header_t *head, int fd_s)
{
	head->magic = COREWAR_EXEC_MAGIC;
	if (find_name(fd_s, head) == 84)
		return (84);
	if (find_comment(fd_s, head) == 84)
		return (84);
	return (0);
}

int verify_len(char *str, int max_len)
{
	if (my_strlen(str) > max_len) {
		write(2, "name too long\n", 14);
		return (-1);
	}
	return (0);
}

int find_name(int fd_s, header_t *head)
{
	char *s = get_next_line(fd_s);
	char *name = NULL;

	if (s == NULL) {
		write(2, ".name missing from header\n", 26);
		return (84);
	}
	while (my_strncmp(".name", s, 5) == 0) {
		s = get_next_line(fd_s);
		if (s == NULL) {
			write(2, ".name missing from header\n", 26);
			return (84);
		}
	}
	name = get_header_name(name, s, 5);
	if (name == NULL || verify_len(name, PROG_NAME_LENGTH) == -1)
		return (84);
	fill_head_name(name, head);
	return (0);
}
