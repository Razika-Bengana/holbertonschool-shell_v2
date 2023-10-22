#include "shell.h"

/**
  * trim - program that removes leading and trailing whitespace from a string
  *
  * @str: the input string to be trimmed
  *
  * this function removes any leading and trailing whitespace characters
  * (space and tab) from the input string 'str';
  * it works by finding the first non-whitespace character from the beginning
  * and the end of the string and then adjusting the string's pointers and
  * null-terminating it accordingly to create a trimmed version of the string;
  *
  * Return: if 'str' is NULL or an empty string, the function returns the input string
  * as is;
  * otherwise, it returns a pointer to the trimmed version of 'str'
  */

char *trim(char *str)
{
	char *front = str;
	char *end = NULL;
	int len;

	if (str == NULL)
		return (NULL);
	if (str[0] == '\0')
		return (str);

	len = _strlen(str);
	end = str + len;

	while (*front == ' ')
		front++;

	if (end != front)
	{
		while (*end == ' ' && end != front)
			end--;
	}
	if (front != str && end == front)
		*str = '\0';
	else if (str + len - 1 != end)
		*(end + 1) = '\0';
	end = str;
	if (front != str)
	{
		while (*front)
			*end++ = *front++;
		*end = '\0';
	}

	return (str);
}
