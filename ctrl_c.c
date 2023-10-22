#include "shell.h"

/**
  * ctrl_c - program that handles the Ctrl+C signal interrupt
  *
  * @signal: the signal received
  *
  * this function is responsible for handling the Ctrl+C signal, which is sent
  * to terminate a running process in the shell;
  * it simply prints a newline and the shell prompt "$ " to the standard output,
  * effectively cancelling the currently running command and providing a fresh
  * prompt for a new command
  *
  * Return: nothing (void)
  */

void ctrl_c(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	write(1, "$ ", 2);
}
