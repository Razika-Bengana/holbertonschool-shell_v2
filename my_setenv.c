#include "shell.h"


char **my_environ;
extern char **environ;


/**
  * copy_environ - program that creates a copy of the environment variables
  *
  * this function creates a copy of the environment variables stored in the 'environ'
  * global variable;
  * it calculates the number of environment variables, allocates memory for the copy,
  * and duplicates each environment variable using '_strdup';
  * the copied environment is terminated with a NULL pointer to indicate the end;
  *
  * if any memory allocation fails, the function returns NULL, and it handles
  * errors using 'perror';
  *
  * Return: a dynamically allocated array containing a copy of the environment variables,
  * or NULL on memory allocation failure
  */

char **copy_environ(void)
{
    int i, len;
    for (len = 0; environ[len]; len++);
    char **new_environ = calloc(len + 1, sizeof(char *));
    if (new_environ == NULL)
    {
        perror("calloc");
        return (NULL);
    }
    for (i = 0; i < len; i++)
    {
        new_environ[i] = _strdup(environ[i]);
        if (new_environ[i] == NULL)
        {
            perror("strdup");
            return (NULL);
        }
    }
    new_environ[len] = NULL;
    return new_environ;
}

/**
  * my_setenv - program that sets or updates an environment variable
  *
  * @name: the name of the environment variable
  * @value: the value to set for the environment variable
  *
  * this function sets or updates an environment variable with the specified 'name'
  * and 'value';
  * it first calculates the total length needed for the new environment
  * variable entry and allocates memory for it using 'calloc';
  * if the environment variable already exists, it updates its value; otherwise,
  * it creates a new entry;
  * if memory allocation fails at any point, the function handles errors using 'perror';
  *
  * the function ensures that the environment is correctly terminated with a NULL
  * pointer and updates the global 'my_environ' variable with the new environment;
  *
  * Return: 0 on success, -1 on memory allocation failure
  */

int my_setenv(const char *name, const char *value)
{
    int i;
    char *new_entry;
    int len_name = _strlen(name);
    int len_value = _strlen(value);
    int total_len = len_name + len_value + 2;

    new_entry = calloc(total_len, sizeof(char));
    if (new_entry == NULL)
    {
        perror("calloc");
        return (-1);
    }
    _strcat(new_entry, name);
    _strcat(new_entry, "=");
    _strcat(new_entry, value);

    for (i = 0; my_environ[i]; i++)
    {
        if (_strncmp(my_environ[i], name, len_name) == 0 && my_environ[i][len_name] == '=')
        {
            free(my_environ[i]);
            my_environ[i] = new_entry;
            return (0);
        }
    }

    char **new_environ = calloc(i + 2, sizeof(char *));
    if (new_environ == NULL)
    {
        perror("calloc");
        free(new_entry);
        return (-1);
    }

    for (int j = 0; j < i; j++)
    {
        new_environ[j] = my_environ[j];
    }
    new_environ[i] = new_entry;
    new_environ[i + 1] = NULL;

    free(my_environ);
    my_environ = new_environ;

    return (0);
}
