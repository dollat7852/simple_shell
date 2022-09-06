#include "shell.h"

/**
 * print - a funtion that print to specified output
 * @var: char to be printed
 * @fd: where to be printed , STDOUT/STDERR
 * Return: int
 */

int print(char *var, int fd)
{
	return (write(fd, var, _strlen(var)));
}
