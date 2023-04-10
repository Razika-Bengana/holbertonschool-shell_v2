#include <stdio.h>
#include <unistd.h>
#include "shell.h"

pid_t _getppid(void)
{
	pid_t parent;

	parent = getpid();
	return (parent);
}
