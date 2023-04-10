#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>

int readcmd(void)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	ssize_t line_size;

	printf("#cisfun$ ");

	line_size = getline(&line_buf, &line_buf_size, stdin);
	printf("%s\n", line_buf);

	free(line_buf);
	line_buf = NULL;

	return EXIT_SUCCESS;
}


