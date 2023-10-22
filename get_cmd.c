#include "shell.h"

#define MAX_CMD_LENGTH 1024

/**
 * get_cmd - program that reads a command line from the standard input
 *
 * this function reads a command line from the standard input and stores it in
 * a dynamically allocated string;
 * it uses the 'getline' function to read input and automatically allocates
 * memory as needed to accommodate the user's input;
 * the function returns the input as a string and ensures that any newline character
 * ('\n') at the end of the input is replaced with a null terminator ('\0');
 *
 * Return: a dynamically allocated string containing the user's input
 * or NULL on failure or when reaching the end of input (EOF)
 */

char *get_cmd(void)
{
    char *cmd = NULL;
    size_t cmd_size = 0;
    ssize_t bytes_read;

    bytes_read = getline(&cmd, &cmd_size, stdin);

    if (bytes_read == -1)
    {
        free(cmd);
        return NULL;
    }

    if (bytes_read > 0 && cmd[bytes_read - 1] == '\n')
    {
        cmd[bytes_read - 1] = '\0';
    }

    return cmd;
}


