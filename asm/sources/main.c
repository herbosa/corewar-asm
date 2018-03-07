/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** corewar
*/

#include "asm.h"
int file_parser();

char *my_strncpy(char *dest, char const *src, int i)
{
	int j = 0;

	while (j < i && src[j]) {
		dest[j] = src[j];
		j = j + 1;
	}
	dest[j] = 0;
	return (dest);
}

char *my_strndup(char *str, int i)
{
	char *s = malloc(sizeof(char) * my_strlen(str) + 2);

	if (s == 0)
		return (0);
	my_strncpy(s, str, i);
	return (s);
}

char *my_strcpy(char *dest, char const *src)
{
	int j = 0;

	while (src[j]) {
		dest[j] = src[j];
		j = j + 1;
	}
	dest[j] = 0;
	return (dest);
}

char *my_strdup(char *str)
{
	char *s = malloc(sizeof(char) * my_strlen(str) + 2);

	if (s == 0)
		return (0);
	my_strcpy(s, str);
	return (s);
}

char *my_concat(char *src, char *dest, int j)
{
	int i = 0;

	while (src[i]) {
		dest[j + i] = src[i];
		i = i + 1;
	}
	dest[j + i] = '\0';
	return (dest);
}

char *my_strcat(char *str, int nblist, ...)
{
	va_list listarg;
	char *src;
	char *dest;
	int j;

	va_start(listarg, nblist);
	while (nblist != 1) {
		src = my_strdup(va_arg(listarg, char*));
		j = my_strlen(str);
		dest = malloc(sizeof(char) * (j + 2) * my_strlen(src));
		dest = my_strcpy(dest, str);
		dest = my_concat(src, dest, j);
		nblist = nblist - 1;
		str = my_strdup(dest);
	}
	va_end(listarg);
	return (dest);
}

char *get_name(char *name)
{
	int i = 0;
	int j = 0;

	while (name[i]) {
		if (name[i] == '/')
			j = i + 1;
		i = i + 1;
	}
	if (name[i - 2] == '.' && name[i - 1] == 's') {
		name[i - 2] = '\0';
	} else
		return (NULL);
	name = name + j;
	name = my_strcat(name, 2, ".cor\0");
	return (name);
}

char *get_header_name(char *name, char *s, int i)
{
	int j = 0;

	name = malloc(sizeof(char) * my_strlen(s));
	if (s[i] == '\0')
		return (NULL);
	while (s[i] != '"') {
		i = i + 1;
		if (s[i] == '\0')
			return (NULL);
	}
	i = i + 1;
	while (s[i] != '"') {
		name[j] = s[i];
		i = i + 1;
		j = j + 1;
		if (s[i] == '\0')
			return (NULL);
	}
	name[j] = '\0';
	return (name);
}

char *get_header_comment(char *name, char *s, int i)
{
	int j = 0;

	name = malloc(sizeof(char) * my_strlen(s));
	if (s[i] == '\0')
		return (NULL);
	while (s[i] != '"') {
		i = i + 1;
		if (s[i] == '\0')
			return (NULL);
	}
	i = i + 1;
	while (s[i] != '"') {
		name[j] = s[i];
		i = i + 1;
		j = j + 1;
		if (s[i] == '\0')
			return (NULL);
	}
	name[j] = '\0';
	return (name);
}

int verify_len(char *str, int max_len)
{
	if (my_strlen(str) > max_len) {
		write(2, "name too long\n", 14);
		return (-1);
	}
	return (0);
}

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
	if (name == NULL || verify_len(name, PROG_NAME_LENGTH) == - 1)
		return (84);
	fill_head_name(name, head);
	return (0);
}

int find_comment(int fd_s, header_t *head)
{
	char *s = get_next_line(fd_s);
	char *name = NULL;

	if (s == NULL) {
		write(2, ".comment missing from header\n", 29);
		return (84);
	}
	while (my_strncmp(".comment", s, 8) == 0) {
		s = get_next_line(fd_s);
		if (s == NULL) {
			write(2, ".comment missing from header\n", 29);
			return (84);
		}
	}
	name = get_header_comment(name, s, 5);
	if (name == NULL || verify_len(name, COMMENT_LENGTH) == - 1)
		return (84);
	fill_head_comment(name, head);
	return (0);
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

int write_head(int fd_s, int fd_cor, int a)
{
	header_t head;

	if (fill_header(&head, fd_s) == 84)
		return (84);
	if (write_nbr(head.magic, fd_cor) == -1)
		return (84);
	if (write(fd_cor, head.prog_name, PROG_NAME_LENGTH) == -1)
		return (84);
	if (write_nbr(0, fd_cor) == -1)
		return (84);
	if (write_nbr(a, fd_cor) == -1)
		return (84);
	if (write(fd_cor, head.comment, COMMENT_LENGTH) == -1)
		return (84);
	if (write_nbr(0, fd_cor) == -1)
		return (84);
	return (0);
}

char **file_to_tab(int fd_s)
{
	char *s = get_next_line_2(fd_s);
	char **tab = malloc(sizeof(char *) * 2);
	int i = 0;
	int x = 0;

	if (s == NULL)
		return (NULL);
	while (s != NULL) {
		tab = realloc(tab, sizeof(char *) * (i + 3));
		if (tab == NULL)
			return (NULL);
		for (x = 0; x < my_strlen(s); x = x + 1) {
			if (s[x] == ' ' && s[x - 1] == ':') {
				tab[i] = my_strndup(s, x - 1);
				s = s + x;
				i = i + 1;
				tab = realloc(tab, sizeof(char *) * (i + 3));
				x = my_strlen(s);
			}
		}
		tab[i] = my_strdup(s);
		tab[i + 1] = '\0';
		s = get_next_line_2(fd_s);
		i = i + 1;
	}
	tab[i] = '\0';
	return (tab);
}

int main(int argc, char **argv)
{
	int fd_s = 0;
	int fd_cor = 0;
	char *new_name;

	if (argc != 2)
		return (84);
	fd_s = open(argv[1], O_RDONLY);
	if (fd_s == -1)
		return (84);
	new_name = get_name(argv[1]);
	if (new_name == NULL)
		return (84);
	fd_cor = open(new_name, O_CREAT | O_RDWR, S_IROTH |
		S_IRUSR | S_IRGRP | S_IWUSR | S_IWGRP);
	if (fd_cor == -1)
		return (84);
	return(file_parser(file_to_tab(fd_s), fd_s, fd_cor));
}
