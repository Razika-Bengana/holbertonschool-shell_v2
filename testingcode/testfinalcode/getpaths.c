#include "shell.h"

/**
  * getpath - gets the path of the command
  * @getcmd: command to find the path
  * Return: path of the command
  */

char *getpath(char *getcmd)
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
		strncat(newpath, tab_path[i]);
		strncat(newpath, "/");
		strncat(newpath, getcmd);
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
