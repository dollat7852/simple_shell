#include "shell.h"
/**
 * _getline - get a stream of data inpit from STDIN
 * Return: NULL
 */
char *_getline(void)
{
	int buflen = READ_BUF;
	int readlen, position = 0;
	char *buffer = malloc(buflen * sizeof(char));
	char c;

	if (buffer == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		readlen = read(STDIN_FILENO, &c, 1);
		if (c == EOF || !readlen)
		{
			if (isatty(STDIN_FILENO) == 1) /* check if input is from terminal */
			{
				print("\n", STDOUT_FILENO);
				return (NULL);
			}
		}
		else if (c == '\n' || !readlen)
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
		if (position  >= buflen)
		{
			buflen += READ_BUF;
			buffer = _realloc(buffer, buflen);
			if (!buffer)
			{
				perror("Failed to re-allocate");
				exit(EXIT_FAILURE);
			}
		}
	}
}
