#include "shell.h"

/**
  * func_split - program that splits a string into an array of tokens
  *
  * @line: The input string to be split
  *
  * this function takes an input string 'line' and splits it into an array of
  * tokens using space (' ') as the delimiter;
  * it dynamically allocates memory for an array to hold these tokens and
  * extracts them using the 'strtok' function;
  * the array is terminated with a NULL pointer to indicate the end of tokens;
  *
  * the function handles memory allocation errors and exits the program if
  * memory allocation fails;
  *
  * Return: An array of tokens extracted from the input string,
  * or NULL on memory allocation failure
  */

char **func_split(char *line)
{
	int size = 64;
	int i = 0;
	char **tab_token = malloc(size * sizeof(char *));
	char *token;

	if (tab_token == NULL)
	{
		perror("Error : malloc");
		free(tab_token);
		free(line);
		exit(1);
	}

	token = strtok(line, " ");
	while (token != NULL)
	{
		tab_token[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	tab_token[i] = NULL;
	return (tab_token);
}
