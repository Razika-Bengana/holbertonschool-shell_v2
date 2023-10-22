#include "shell.h"

/**
  * split_env - program that splits a colon-separated string into an array of strings
  *
  * @path: the colon-separated string to be split
  *
  * this function takes a colon-separated string 'path' (commonly used for
  * representing file system paths or environment variable values) and splits
  * it into an array of strings using the colon (':') character as the delimiter;
  * it dynamically allocates memory for the array and extracts the components
  * using the 'strtok' function;
  * the resulting array is terminated with a NULL pointer to indicate the end;
  *
  * if memory allocation fails, the function handles the error using 'perror'
  * and exits the program;
  *
  * Return: an array of strings containing the split components
  */

char **split_env(char *path)
{
	int size = 1024;
	int i = 0;
	char **tab_path = malloc(size * sizeof(char *));
	char *token;

	if (tab_path == NULL)
	{
		perror("Error : malloc");
		exit(1);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		tab_path[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	tab_path[i] = NULL;

	return (tab_path);
}
