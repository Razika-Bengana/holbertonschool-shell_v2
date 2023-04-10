#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
/* error strings */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

char *_read(void);
char **_split(char *line);
int _execve(char **args);
void freegrid(char **grid);
void _printenv(void);
char *getpath(char *getcmd);
int str_cmp(char *s1, char *s2);
int str_len(char *s);
int str_ncmp(char *s1, char *s2, int n);
void ctrl_c(int signal);
char **split_env(char *path);

pid_t _getppid(void);

/** STRING FUNCTION */

char *_strtok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);

#endif
