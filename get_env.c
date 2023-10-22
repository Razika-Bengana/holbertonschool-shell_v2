#include "shell.h"

/**
 * get_env - get the environment variable
 * @getcmd: command
 * Return: the environment variable
 */

char **my_environ;

char *get_env(char *getcmd)
{
	int i, size;

	size = _strlen(getcmd);
	for (i = 0; my_environ[i]; i++)
	{
		if (_strncmp(my_environ[i], getcmd, size) == 0)
			return (my_environ[i] + size + 1);
	}
	return (NULL);
}
