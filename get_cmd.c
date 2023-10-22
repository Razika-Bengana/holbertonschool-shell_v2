#include "shell.h"

#define MAX_CMD_LENGTH 1024

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


