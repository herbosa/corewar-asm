/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** get_next_line.h
*/

#ifndef READ_SIZE
#define READ_SIZE (100)

#endif

#ifndef GNL_H_
#define GNL_H_

char *get_next_line(int fd);
char *get_next_line_2(int fd);

struct gnl_t {
	char *ret;
	char *mem;
	int cnt;
};

typedef struct gnl_t gnl_s;

#endif
