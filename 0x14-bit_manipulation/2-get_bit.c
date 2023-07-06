#include "main.h"
#include <stdio.h>

/**
 * get_bit - a function that returns the value of a bit at a given index
 * @n: number to traverse its bits
 * @index: index starting from 0, of the bit we want to get
 * Return: Value of bit at the indexed position, -1 on error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int buffer;

	if (index > 64)
		return (-1);

	buffer = n >> index;

	return (buffer & 1);
}
