#include "shell.h"

/**
 * shell_execute - an helper function to execute system call
 * @command: command to be executed
 * @cmd_type: command type e.g internal, external, path, invalid
 * Return: null
 */
void shell_execute(char **command, int cmd_type)
{
	int stat;
	pid_t PID;

	if (cmd_type == EXTERNAL_CMD || cmd_type == PATH_CMD)
	{
		PID = fork();

		if (PID == 0)
		{
			execute(command, cmd_type);
		}
		if (PID < 0)
		{
			perror("failed to call fork");
			exit(1);
		}
		else
			wait(&stat);
	}
	else
		execute(command, cmd_type);
}

/**
 * check_command - a function to determine command type
 * @command: command to be checked
 * Return: int (see header file for more)
 */

int check_command(char *command)
{
	int i = 0;
	char *int_cmd[] = {"exit", "cd", "env", NULL};

	while (command[i])
	{
		if (command[i] == '/')
			return (EXTERNAL_CMD);
		i++;
	}

	i = 0;
	while (int_cmd[i] != NULL)
	{
		if (_strcmp(command, int_cmd[i]) == 0)
			return (INTERNAL_CMD);
		i++;
	}

	return (INVALID_CMD);
}

/**
 * execute - make a system call to execute a command
 * @commands: commands is a string passed by user
 * @cmd_type: type of command (see command type above)
 */
void execute(char **commands, int cmd_type)
{
	void (*func)(char **command);

	switch (cmd_type)
	{
		case EXTERNAL_CMD:
			{
				if (execve(commands[0], commands, NULL) == -1)
				{
					perror(getenv("PWD"));
					exit(2);
				}
				break;
			}
		case INTERNAL_CMD:
			{
				func = get_func(commands[0]);
				func(commands);
				break;
			}
		case PATH_CMD:
			{
				break;
			}
		case INVALID_CMD:
			{
				print(*commands, STDOUT_FILENO);
				print(": command not found\n", STDERR_FILENO);
				exit(1);
				break;
			}
	}
}
