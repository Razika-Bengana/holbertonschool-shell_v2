#include <stdio.h>
#include <string.h>

int main()
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	ssize_t line_size;

	printf("$ ");
	line_size = getline(&line_buf, &line_buf_size, stdin);

	int in_size = strlen(line_buf);
	char delim[] = " ";
	
	char *ptr = strtok(line_buf, delim);

	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);
	}

/**	
 * for (int i = 0; i < in_size; i++)
	{
		printf("%d\n", line_buf[i]);
	}
	printf("\n");
*/

	return (0);
}
