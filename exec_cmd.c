#include "shell.h"

/**
  * exec_cmd - program that executes a command with the given arguments
  *
  * @args: an array containing the command and its arguments
  *
  * this function is responsible for executing a command with the provided
  * arguments;
  * it first forks a new process to run the command;
  * in the child process, it checks if the command is an absolute path or in
  * the system's PATH;
  * if it's in the PATH, it retrieves the full path using 'get_path'function;
  * then, it attempts to execute the command using 'execve' with the
  * provided arguments and environment variables
  * (using 'my_environ' instead of 'environ');
  * in case of any errors, it prints appropriate error messages
  *
  * Return: 1 on successful execution, 0 on failure
  */

int exec_cmd(char **args)
{
	pid_t my_pid;
	char *getcmd = args[0];
	int status;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error : fork");
	}

	if (my_pid == 0)
	{

		if (getcmd[0] == '/' || getcmd[0] == '.')
		{
			getcmd = args[0];
		}
		else
		{
			getcmd = get_path(args[0]);
		}
		if (args[0] == NULL)
		{
			perror("Error : no argument");
		}
		if (getcmd == NULL)
		{
			free(getcmd);
			perror("Error : execve");
			return (0);
		}
		else
        {
            execve(getcmd, args, my_environ); /* Use my_environ instead of environ */
        }
	}
	else
	{
		wait(&status);
	}
	return (1);
}
