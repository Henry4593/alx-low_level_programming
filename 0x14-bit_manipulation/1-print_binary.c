#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints binary representation of unsigned long int
 * @n: decimal number to convert to binary
 */

void print_binary(unsigned long int n)
{
	unsigned long int buffer;
	int requiredShifts;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (buffer = n, requiredShifts = 0; (buffer >>= 1) > 0; requiredShifts++)
		{}

	for (; requiredShifts >= 0; requiredShifts--)
	{
		if ((n >> requiredShifts) & 1)
			printf("1");
		else
			printf("0");
	}
}
