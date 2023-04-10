#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	FILE *fp = STDIN_FILENO(FILENAME, "r");

