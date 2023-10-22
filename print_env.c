#include "shell.h"

/**
  * _printenv - function that print the environment variables
  */

char **my_environ;

void print_env(void)
{
	int i;
	int lengh;

	for (i = 0; my_environ[i]; i++)
	{
		lengh = _strlen(my_environ[i]);
		write(1, my_environ[i], lengh);
		write(1, "\n", 1);
	}
}
