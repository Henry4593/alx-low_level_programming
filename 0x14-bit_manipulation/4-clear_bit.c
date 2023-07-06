#include "main.h"
#include <stdio.h>

/**
 * clear_bit - a function that sets the value of a bit to 0 at a given index.
 * @n: decimal number to traverse the bits and make changes
 * @index: index position to make bit(s) changes
 * Return: 1 on success, -1 on error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int y;
	unsigned int temp_store;

	if (index > 64)
		return (-1);
	temp_store = index;
	for (y = 1; temp_store > 0; y *= 2, temp_store--)
	{}

	if ((*n >> index) & 1)
		*n -= y;

	return (1);
}
