/*
** EPITECH PROJECT, 2017
** the_last_file.c
** File description:
** 5 more functions
*/

#include "asm.h"

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

char **clean_label(char *s, int *i, char **tab)
{
	int x = 0;
	int j = *i;

	for (x = 1; x < my_strlen(s); x = x + 1) {
		if ((s[x] == ' ' || s[x] == '\t') && s[x - 1] == ':') {
			if (x >= 2 && s[x - 2] == '%')
				exit(84);
			tab[*i] = my_strndup(s, x);
			s = s + x;
			*i = *i + 1;
			tab = realloc(tab, sizeof(char *) * (j + 4));
			x = my_strlen(s);
		}
	}
	tab[*i] = my_strdup(s);
	tab[*i + 1] = '\0';
	return (tab);
}

char **file_to_tab(int fd_s)
{
	char *s = get_next_line_2(fd_s);
	char **tab = malloc(sizeof(char *) * 2);
	int i = 0;

	if (s == NULL)
		return (NULL);
	while (s != NULL) {
		tab = realloc(tab, sizeof(char *) * (i + 4));
		if (tab == NULL)
			return (NULL);
		tab = clean_label(s, &i, tab);
		s = get_next_line_2(fd_s);
		i = i + 1;
	}
	tab[i] = '\0';
	for (i = 0; tab[i]; i = i + 1)
		tab[i] = my_cleaner(tab[i]);
	check_instr(tab);
	return (tab);
}

int is_label_char(char c)
{
	char *str = my_strdup("abcdefghijklmnopqrstuvwxyz_0123456789");
	int i = 0;

	for (i = 0; str[i]; i = i + 1) {
		if (c == str[i])
			return (1);
	}
	return (0);
}
