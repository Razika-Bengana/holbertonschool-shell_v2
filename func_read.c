#include "shell.h"

/**
  * func_read - program that reads a line of input from the standard input
  *
  * this function is responsible for reading a line of input from the standard
  * input (usually user input);
  * it uses the `getline` function to dynamically allocate memory for the input line,
  * taking care of resizing the buffer as needed;
  * the function trims leading and trailing whitespace from the input
  * line and checks for empty lines or lines containing only a newline character;
  *
  * Return: a dynamically allocated string containing the input line, or NULL
  * if no valid input was provided
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
