/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *gnl_strcpy(char *dest, char const *src, int j)
{
	int i = 0;

	while (src[j]) {
		dest[i] = src[j];
		j = j + 1;
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

char *gnl_strcat(char *str, char *src, int x)
{
	char *dest;
	int j = 0;
	int z = 0;
	int i = 0;

	for (z = z; src[z]; z = z + 1);
	for (j = j; str[j]; j = j + 1);
	dest = malloc(sizeof(char) * (j + 2) + z);
	dest = gnl_strcpy(dest, str, 0);
	while (src[i] && i != x) {
		dest[j + i] = src[i];
		i = i + 1;
	}
	dest[j + i] = '\0';
	return (dest);
}

gnl_s *read_and_display_read_line(int fd, gnl_s *gnl, char *ret, int i)
{
	int nb_read = 0;
	int j = 0;

	gnl = malloc(sizeof(gnl_s) * 2);
	gnl->ret = ret;
	gnl->mem = malloc(sizeof(char) * (READ_SIZE + 1));
	nb_read = read(fd, gnl->mem, READ_SIZE);
	if (nb_read <= 0) {
		gnl->ret = NULL;
		return (gnl);
	}
	gnl->mem[nb_read] = '\0';
	for (i = i; gnl->mem[i] != '\0'; i = i + 1)
		if (gnl->mem[i] == '\n')
			j = 1;
	gnl->ret = gnl_strcat(gnl->ret, gnl->mem, -1);
	if (j != 0) {
		return (gnl);
	} else
		read_and_display_read_line(fd, gnl, gnl->ret, 0);
}

gnl_s *more_line(gnl_s *gnl, char **start)
{
	int i = 0;
	int j = 0;

	if (!gnl)
		*start[0] = '\0';
	if (gnl) {
		j = 1;
		gnl->cnt = 0;
	}
	for (i = 0; j == 1 && gnl->mem[i] != '\0'; i = i + 1)
		if (gnl->mem[i] == '\n') {
			gnl->cnt = 1;
			break;
		}
	if (j == 1 && gnl->cnt == 1) {
		gnl->ret = gnl_strcat("\0", gnl->mem, i);
		gnl->mem = gnl->mem + i + 1;
	}
	return (gnl);
}

char *get_next_line(int fd)
{
	static gnl_s *gnl;
	int i = 0;
	char *start = malloc(sizeof(char) * (READ_SIZE + 1));

	if (start == NULL || fd < 0 || READ_SIZE < 0)
		return (NULL);
	gnl = more_line(gnl, &start);
	if (gnl && gnl->cnt == 1)
		return (gnl->ret);
	if (gnl)
		start = gnl_strcpy(start, gnl->mem, 0);
	gnl = read_and_display_read_line(fd, gnl, start, 0);
	if (!gnl->ret)
		return (NULL);
	for (i = 0; gnl->mem[i] != '\n' && gnl->mem[i]; i = i + 1);
	gnl->mem = gnl->mem + i + 1;
	for (i = 0; gnl->ret[i] != '\n'; i = i + 1);
	start = gnl_strcat("\0", gnl->ret, i);
	gnl->ret = NULL;
	return (start);
}
