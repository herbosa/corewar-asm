/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** corewar
*/

#include "asm.h"

char *my_strcpy(char *dest, char const *src)
{
        int j = 0;

        while (src[j]) {
                dest[j] = src [j];
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
	fd_cor = open(new_name, O_CREAT | O_RDWR, S_IRWXU);
	if (fd_cor == -1)
		return (84);
	return (0);
}
