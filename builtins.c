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
	int num_token = 0, arg;

	while (command[num_token] != NULL)
		num_token++;
	if (num_token == 1)
	{
		/*free(command);*/
		/*free(environ);*/
		exit(1);
	}
	else if (num_token == 2)
	{
		arg = _atoi(command[1]);
		if (arg < 0)
		{
			perror(*command);
			exit(EXIT_FAILURE);
		}
		else
		{
			/*free(command);*/
			/*free(environ);*/
			exit(arg);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}

void ch_dir(char **command)
{
	(void) command;
}
