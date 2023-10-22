#include "shell.h"

void handle_redirection(char *command[], char *file)
{
    int fd;
    pid_t pid;
    char *path = "/bin/";
    char fullpath[50];

    _strcat(fullpath, path);
    _strcat(fullpath, command[0]);

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid == 0)
    {
        fd = open(file, O_WRONLY | O_CREAT, 0644);
        if (fd == -1)
        {
            perror("open");
            exit(1);
        }

        if (dup2(fd, STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }

        if (execve(fullpath, command, NULL) == -1)
        {
            perror("execve");
            exit(1);
        }
    }
    else
    {
        wait(NULL);
    }
}



void handle_command_with_redirection(char **args)
{
    char *file = NULL;
    char **command = NULL;
    int i, j;

    for (i = 0; args[i] != NULL; i++)
    {
        if (_strcmp(args[i], ">") == 0)
        {
            file = args[i + 1];
            break;
        }
    }

    if (file != NULL)
    {
        command = malloc((i + 1) * sizeof(char *));
        if (command == NULL)
        {
            perror("malloc");
            exit(1);
        }

        for (j = 0; j < i; j++)
        {
            command[j] = args[j];
        }
        command[i] = NULL;

        handle_redirection(command, file);
        free(command);
    }
    else
    {
        fprintf(stderr, "Syntax error: Missing file name for redirection\n");
    }
}
