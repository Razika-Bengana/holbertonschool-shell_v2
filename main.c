#include "shell.h"

/**
  * main - The entry point of a simple shell program
  *
  * this function serves as the entry point of a simple shell program;
  * it initializes necessary variables and structures, sets up the signal handler
  * for Ctrl+C (SIGINT), and enters a loop where it repeatedly reads user input
  * and executes commands until the user exits;
  *
  * within the loop, the function checks if the shell is running in interactive
  * mode and prints a prompt if it is;
  * it reads a line of input using the 'func_read' function and processes user commands;
  * it supports built-in commands like "exit," "env," and "cd" (handled by other functions)
  * and executes other shell commands using the 'exec_cd' function;
  *
  * the function also handles memory cleanup and frees allocated resources
  * before exiting the shell;
  *
  * Return: 0 on successful execution, 1 on failure
  */

char **my_environ = NULL;

int main(void)
{
    char old_pwd[1024];
    my_environ = copy_environ();
    if (my_environ == NULL)
    {
        perror("Failed to initialize my_environ.");
        return 1;
    }
    if (getcwd(old_pwd, sizeof(old_pwd)) == NULL)
    {
        perror("getcwd");
        return 1;
    }
    my_setenv("OLDPWD", old_pwd);


	int status = 1;
	char *line;
	char **args;
    int i;

	signal(SIGINT, ctrl_c);
	while (status)
	{
		status = isatty(0);

		if (status == 1)
			write(1, "$ ", 2);

		line = func_read();
		if (line == NULL || (_strcmp(line, "exit") == 0))
		{
			free(line);
			exit(0);
		}
		else if (_strcmp(line, "env") == 0)
		{
			print_env();
			free(line);
			continue;
		}
		args = func_split(line);
		if (args == NULL)
		{
			free_grid(args);
			free(line);
			free(args);
			continue;
		}
		if (line[0] != '\n' || line[1] != '\0')
        {
            status = exec_cd(args);
        }
		free(line);
		free(args);
	}
    for (i = 0; my_environ[i]; i++)
    {
        free(my_environ[i]);
    }
    free(my_environ);

    return (0);
}
