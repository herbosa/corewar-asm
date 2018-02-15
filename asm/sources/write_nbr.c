/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
                       

# define PROG_NAME_LENGTH        128
# define COMMENT_LENGTH          2048

struct header_s
{
   int  magic;
# define COREWAR_EXEC_MAGIC      0xea83f3        /* why not */
   char prog_name[PROG_NAME_LENGTH + 1];
   int  prog_size;
   char comment[COMMENT_LENGTH + 1];
};

int write_nbr(int nbr, int fd)
{
	int i = 0;
	int j = 0;
	int wrt = 0;
	int mem = nbr;

	nbr = mem / 256 / 256 / 256;
       	wrt = write(fd, &nbr, 1);
	if (wrt == -1)
                return (-1);
	nbr = mem / 256 / 256;
       	wrt = write(fd, &nbr, 1);
	if (wrt == -1)
                return (-1);
	nbr = mem / 256;
       	wrt = write(fd, &nbr, 1);
	if (wrt == -1)
                return (-1);
	nbr = mem;
	wrt = write(fd, &nbr, 1);
	if (wrt == -1)
                return (-1);
	return (0);
}



int main(int argc, char **argv)
{
	struct header_s stc;
	int i = 0;
        int fd = 0;
        int wrt = 0;

        fd = open("data_test", (O_CREAT)|O_RDWR, S_IRWXU);
        if (fd == 0)
                return (84);
	int a = 255;
	write_nbr(a, fd);
	return (0);
}
