#include "shell.h"

int exec_cd(char **args)
{
    if (_strcmp(args[0], "cd") == 0)
    {
        return func_cd(args);
    }
    else
    {
        return exec_cmd(args);
    }
}


