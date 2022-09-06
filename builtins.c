#include "shell.h"

/**
 * env - a function that print out the current path
 * Return: nothing
 */

void env(char **command __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		print(environ[i++], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

void quit(char **command)
	{
	(void) command;
}

void ch_dir(char **command)
{
	(void) command;
}
