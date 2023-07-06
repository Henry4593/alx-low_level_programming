#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: string of binary digits/string of bits
 * Return: converted decimal number, 0 on failure
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal = 0;
	int len = 0, power = 0, i = 0;

	if (!b)
		return (0);
	while (b[len] != '\0')
	{
		if (b[len] != '1' && b[len] != '0')
			return (0);
		len++;

	}
	power = len - 1;

	for (i = 0; i < len; i++)
	{

		if (b[i] == '1')
		{
			decimal += (1 << power);
		}
		power--;
	}

	return (decimal);
}
