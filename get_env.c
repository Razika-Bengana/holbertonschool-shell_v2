#include "shell.h"

/**
  * get_env - program that retrieves the value of an environment variable
  *
  * @getcmd: the name of the environment variable to retrieve
  *
  * this function is responsible for searching and retrieving the value of an
  * environment variable specified by the 'getcmd' parameter;
  * it iterates through the 'my_environ' array, which stores environment variable
  * definitions, and compares each entry to find a match based on the variable
  * name (substring match);
  *
  * Return: a pointer to the value of the environment variable or NULL if not found
  */

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
