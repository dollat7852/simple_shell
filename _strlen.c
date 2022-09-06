#include "shell.h"
/**
 * _strlen - return the length of a string
 * @var: string input
 * Return: int length of string
 */

int _strlen(char *var)
{
	int i = 0;

	while (var[i] != '\0')
	{
		i++;
	}
	return (i);
}
