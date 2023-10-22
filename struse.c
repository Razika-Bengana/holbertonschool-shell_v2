#include "shell.h"

/**
 * _strcat - program that concatenates two strings
 *
 * @dest: the destination string to which 'src' will be appended
 * @src: the source string that will be appended to 'dest'
 *
 * Return: a pointer to the modified 'dest' string
 */

char *_strcat(char *dest, const char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - program that compares two strings
 *
 * @s1: the first string to be compared
 * @s2: the second string to be compared
 *
 * Return: 0 if 's1' is equal to 's2', a positive value if 's1' is greater,
 * and a negative value if 's2' is greater
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			break;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strlen - program that calculates the length of a string
 *
 * @s: the input string
 *
 * Return: the length of the string 's'
 */

int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		++i;
	}
	return (i);
}

/**
 * _strncmp - program that compares two strings up to a specified length
 *
 * @s1: the first string to be compared
 * @s2: the second string to be compared
 * @n: the maximum number of characters to compare
 *
 * Return: 0 if the first 'n' characters of 's1' are equal to 's2', a positive
 * value if 's1' is greater, and a negative value if 's2' is greater
 */

int _strncmp(const char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}




