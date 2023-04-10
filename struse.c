#include "shell.h"

/**
 * _strcat - Concatonates two strings
 * @dest: The destination string
 * @src: The source string
 * Return: dest
 */

char *_strcat(char *dest, char *src)
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
  * _strcmp - function that compare two strings
  * @s1: String 1
  * @s2: String 2
  * Return: 0 if s1 == s2, negative value if s1 < s2 and positive if s1 > s2
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
 * _strlen - size of string
 * @s: string to find size
 * Return: string size
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		++i;
	}
	return (i);
}

/**
 * *_strncmp - function that compare n characters of two strings
 * @s1: String 1
 * @s2: String 2
 * @n: numbers of characters
 * Return: 0 if s1 = s2, negative value if s1 < s2 and positive if s1 > s2
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
