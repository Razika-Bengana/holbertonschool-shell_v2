#include "shell.h"

/**
 * str_len - size of string
 * @s: string to find size
 * Return: string size
 */

int str_len(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		++i;
	}
	return (i);
}
