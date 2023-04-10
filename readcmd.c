#include "shell.h"

/**
  * func_read - function that reads the stdin
  * Return: line if succesful or NULL if failed
  */

char *func_read(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t len = 0;

	len = getline(&line, &size, stdin);

	if (len == -1)
	{
		free(line);
		exit(0);
	}
	line[len - 1] = 0;
	line = trim(line);

	if (line[0] == '\n' || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
