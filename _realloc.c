#include "shell.h"

/**
 * _realloc - a function to reallocate memory size if the initial
 * size is too low
 * @ptr: existing memory location
 * @new_size: new size to be allocated
 * Return: char pointer
 */
char *_realloc(char *ptr, int new_size)
{
	char *new_buffer = malloc(new_size * sizeof(char));

	if (new_buffer == NULL)
	{
		perror("failed to allocate more memory");
		exit(EXIT_FAILURE);
	}

	*new_buffer = *ptr;
	return (new_buffer);
}
