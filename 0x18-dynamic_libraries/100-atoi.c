#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Description: Converts the initial portion of the string pointed to by s
 * to an integer representation.
 *
 * Return: The converted integer.
 */

int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int idx = 0;

	if (s[0] == '-')
	{
		sign = -1;
		idx++;
	}
	while (s[idx] != '\0' && s[idx] >= '0' && s[idx] <= '9')
	{
		result = result * 10 + (s[idx] - '0');
		idx++;
	}

	return (sign * result);
}
