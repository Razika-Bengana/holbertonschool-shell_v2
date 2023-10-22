#include "shell.h"

/**
  * get_path - program that retrieves the full path of an executable file
  *
  * @getcmd: the name of the executable file
  *
  * this function is responsible for retrieving the full path to an executable
  * file specified by the 'getcmd' parameter;
  * it searches for the executable in the directories listed in the 'PATH'
  * environment variable;
  * it dynamically allocates memory for a new path and constructs possible paths
  * by combining each directory from 'PATH' with the 'getcmd';
  * it uses the 'stat' function to check if the constructed path corresponds
  * to an existing file;
  *
  * Return: the full path to the executable file or NULL if not found
  */

char *get_path(char *getcmd)
{
	struct stat st;
	int i;
	char *path = get_env("PATH");
	char **tab_path = split_env(path);
	char *newpath = malloc(sizeof(char) * 64);

	if (newpath == NULL)
	{
		perror("Error : malloc");
		return (NULL);
	}

	for (i = 0; tab_path[i] != NULL; i++)
	{
		newpath[0] = 0;
		_strcat(newpath, tab_path[i]);
		_strcat(newpath, "/");
		_strcat(newpath, getcmd);
		if (stat(newpath, &st) == 0)
		{
			free(tab_path);
			return (newpath);
		}
	}
	free(newpath);
	free(tab_path);
	return (NULL);
}
