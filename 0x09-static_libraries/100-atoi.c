#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert to int
 *
 * Return: the integer value from the string
 */
int _atoi(char *s)
{
	int num = 0, sign = 1;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign = -sign;
		}
		else if (*s >= '0' && *s <= '9')
		{
			num = num * 10 + (*s - '0') * sign;
			if (*(s + 1) < '0' || *(s + 1) > '9')
			{
				break;
			}
		}
		s++;
	}

	return (num);
}
