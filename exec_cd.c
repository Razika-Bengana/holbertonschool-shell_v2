#include "shell.h"

/**
  * exec_cd - program that executes a 'cd' command or delegate to a generic command execution
  *
  * @args: an array containing the command and its arguments
  *
  * this function checks if the command provided in the 'args' array is 'cd,'
  * a command for changing the current directory;
  * if it is, it delegates the execution to the 'func_cd' function, which handles
  * changing directories;
  * if the command is not 'cd,' it delegates the execution to the 'exec_cmd'
  * function, which handles executing other generic shell commands
  *
  * Return: the return value of the executed command or -1 on failure
  */

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


