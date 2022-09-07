#include "shell.h"

/**
 * _atoi - convert a string to int
 * @str: string to be converted
 * Return: converted int/ int value of str
 */

int _atoi(char *str)
{
	int sign = 1, base = 0, i = 0;

	for (i = 0; str[i] != '\0' && (str[i] < '0' || str[i] > '9'); i++)
	{
		if (str[i] == '-' || str[i] == '+')
			sign *= 1 - 2 * (str[i] == '-');
		if (str[i + 1] == '\0')
			return (0);
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		if (base > INT_MAX / 10	|| (base == INT_MAX / 10
			&& str[i] - '0' > 7))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		base = 10 * base + (str[i++] - '0');
	}

	return (base * sign);
}
