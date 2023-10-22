#ifndef SHELL_H
#define SHELL_H

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


extern char **environ;


char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, int n);
char *_strdup(const char *str);

char *func_read(void);
int exec_cmd(char **args);
void free_grid(char **grid);
char **func_split(char *line);
char *get_env(char *getcmd);
char *get_path(char *getcmd);
void print_env(void);
void ctrl_c(int signal);
char **split_env(char *path);
char *trim(char *str);

/* New implementation */
int func_cd(char **args);
int exec_cd(char **args);
int my_setenv(const char *name, const char *value);
char **copy_environ(void);


#endif /* SHELL_H */
