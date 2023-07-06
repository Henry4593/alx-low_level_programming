#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index.
 * @n: decimal number to traverse bits
 * @index: index position to change, beginning from 0
 * Return: 1 on success, -1 on failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int y;

	if (index > 64)
		return (-1);

	for (y = 1; index > 0; index--, y *= 2)
		;
	*n += y;

	return (1);
}
