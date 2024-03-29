#include "shell.h"

/**
  * print_env - program that prints the environment variables to the standard output
  *
  * this function is responsible for printing the environment variables to the
  * standard output (usually the terminal);
  * it iterates through the 'my_environ' array, which holds environment variable
  * definitions, and prints each variable followed by a newline character;
  * the length of each environment variable is determined using the '_strlen'
  * function, and 'write' is used to output the variable's contents to the standard
  * output;
  *
  * Return: nothing (void)
  */

void print_env(void)
{
	int i;
	int lengh;

	for (i = 0; environ[i]; i++)
	{
		lengh = _strlen(environ[i]);
		write(1, environ[i], lengh);
		write(1, "\n", 1);
	}
}
