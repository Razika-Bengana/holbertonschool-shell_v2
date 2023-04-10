#include "shell.h"

/**
  * main - start the shell
  * Return: 1
  */

int main(void)
{
	int status = 1;
	char *line;
	char **args;

	signal(SIGINT, ctrl_c);
	while (status)
	{
		status = isatty(0);

		if (status == 1)
			write(1, "#simple_shell$ ", 9);

		line = _read();
		if (line == NULL || (str_cmp(line, "exit") == 0))
		{
			free (line);
			return (0);
		}
		else if (str_cmp(line, "env") == 0)
		{
			_printenv();
			free(line);
			continue;
		}
		args = _split(line);
		if (args == NULL)
		{
			freegrid(args);
			free(line);
			free(args);
			continue;
		}
		if (line[0] != '\n' || line[1] != '\0')
			status = _execve(args);
		free(line);
		free(args);
	}
	return (0);
}
