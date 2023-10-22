#include "shell.h"

/**
 * _strcat - Concatonates two strings
 * @dest: The destination string
 * @src: The source string
 * Return: dest
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
 * *_strncmp - function that compare n characters of two strings
 * @s1: String 1
 * @s2: String 2
 * @n: numbers of characters
 * Return: 0 if s1 = s2, negative value if s1 < s2 and positive if s1 > s2
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

#include "shell.h"

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 * Return: A pointer to the newly allocated duplicate string
 */
char *_strdup(const char *str)
{
    char *dup_str;
    int length = 0;

    if (str == NULL)
        return NULL;

    while (str[length])
        length++;

    dup_str = malloc(length + 1);
    if (dup_str == NULL)
    {
        perror("malloc");
        return NULL;
    }

    for (int i = 0; i <= length; i++)
        dup_str[i] = str[i];

    return dup_str;
}

