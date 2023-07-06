#include "main.h"
#include <stdio.h>

/**
 * flip_bits - a function that returns the number of bits you would need to
 * flip to get from one number to another.
 * @n: initial number to manipulate bits, to tranform it to the second number m
 * @m: second number
 * Return: number of bits required for flipping
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	int counts;

	diff = n ^ m;
	counts = 0;

	while (diff)
	{
		counts++;
		diff &= (diff - 1);
	}

	return (counts);
}
