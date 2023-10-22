#include "shell.h"

/**
  * func_cd - program that changes the current working directory
  *
  * @args: an array containing the 'cd' command and its arguments
  *
  * this function is responsible for changing the current working directory in a
  * shell program;
  * it takes an array of command and arguments as input, where 'args[0]' is expected
  * to be "cd" and 'args[1]' (if present) is the target directory to change to;
  * it supports the following behaviors:
  *
  * - if 'args[1]' is not provided, it attempts to change to the user's home
  *   directory and updates the environment variable 'PWD' accordingly
  * - if 'args[1]' is "-" (dash), it changes to the previous working directory
  *   as recorded in the 'OLDPWD' environment variable
  * - if 'args[1]' is a valid directory path, it attempts to change to that
  *   directory and updates 'PWD' and 'OLDPWD' accordingly
  *
  * this function also handles error conditions and prints appropriate error
  * messages when necessary
  *
  * Return: 1 on success, -1 on failure.
  */

int func_cd(char **args)
{
    char *home = NULL;
    char old_pwd[1024];
    char new_pwd[1024];

    if (getcwd(old_pwd, sizeof(old_pwd)) == NULL)
    {
        perror("getcwd");
        return -1;
    }

    if (args[1] == NULL)
    {
        home = get_env("HOME");
        if (home == NULL)
        {
            perror("getenv");
            return -1;
        }
        if (chdir(home) != 0)
        {
            perror("chdir");
        }
        else
        {
            printf("Directory changed to %s\n", home);
        }
    }
        /* Gérer la commande cd - */
    else if (_strcmp(args[1], "-") == 0)
    {
        char *oldpwd = get_env("OLDPWD");
        if (oldpwd != NULL)
        {
            if (chdir(oldpwd) != 0)
            {
                perror("chdir");
            }
            else
            {
                printf("Directory changed to %s\n", oldpwd);
            }
        }
        else
        {
            fprintf(stderr, "OLDPWD not set\n");
        }
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("chdir");
        }
        else
        {
            printf("Directory changed to %s\n", args[1]);
        }
    }

    if (getcwd(new_pwd, sizeof(new_pwd)) == NULL)
    {
        perror("getcwd");
        return -1;
    }
    my_setenv("PWD", new_pwd);
    my_setenv("OLDPWD", old_pwd);

    return (1);
}
