#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

pid_t _getppid(void);
int main(int ac, char **av);

/* get_line.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t x);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

#endif
