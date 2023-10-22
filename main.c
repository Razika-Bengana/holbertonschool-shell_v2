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

int main(void)
{
    int status = 1;
    char *line;
    char **args;

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
            status = exec_cmd(args);
        free(line);
        free(args);
    }
    return (0);
}
