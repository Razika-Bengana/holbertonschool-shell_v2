#include "shell.h"

/**
 * main - Child PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};
	pid_t par;
	pid_t childs;
	int i, state;

	for (i = 0; i <5; i++)
	{
		childs = fork();
		if (childs != 0)
		{
			wait(&state);
		}
		if (childs == -1)
		{
			perror("Error:");
			return (1);
		}
		if (childs == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
			else
			{
				execve(argv[0], argv, NULL);
			}
		}
	}
	return (0);
}
