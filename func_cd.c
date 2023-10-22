#include "shell.h"

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

    return (0);
}
