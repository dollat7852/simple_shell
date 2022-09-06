#include "shell.h"
/**
 * is_delimiter - check if the char received is a delimeter
 * see header file for list of delimiters
 * @delimiters: see header file
 * @c: char to be checked against delimiters
 * Return: int
 */
int is_delimiter(const char *delimiters, char c)
{
	int i = 0;

	if (!delimiters)
		return (0);
	while (delimiters[i])
	{
		if (delimiters[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * tokenize - A function that breaks a string into separate tokens
 * using the specified delimiters
 * @str: input string
 * @delim: list of delimiters
 * Return: char pointer to the list of tokenized words
 */

char **tokenize(char *str, const char *delim)
{
	int k = 0, j = 0, i = 0, size = 0, lens[1200];
	char **arr;

	if (str == NULL || !(*str))
		return (NULL);
	/* calc no of words and lengths */
	for (i = 0; str[i]; i++)
	{
		/* skip delimiters */
		if (is_delimiter(delim, str[i]))
			continue;
		/* get the word length */
		j = i;
		while (!is_delimiter(delim, str[i]) && str[i])
			i++;
		if (i > j)
			lens[size++] = i - j;
		if (!str[i])
			break;
	}
	if (!size)
		return (NULL);
	/* create array of strings */
	arr = malloc((size + 1) * sizeof(char *));
	for (i = 0; str[i]; i++)
	{
		if (is_delimiter(delim, str[i]))
			continue;
		/* copy the word */
		arr[k] = malloc((lens[k] + 1) * sizeof(char));
		j = 0;
		while (!is_delimiter(delim, str[i]) && str[i])
			arr[k][j++] = str[i++];
		arr[k++][j] = '\0';
		if (!str[i])
			break;
	}
	arr[size] = NULL;
	return (arr);
}

