#include "main.h"

/**
 * _memset - A program that fills
 * n bytes of memory with a constant value
 * @s: pointer to allocated memory location
 * @b: constant value to be allocated
 * @n: number of bytes to fill
 * Return: memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int count = 0;
	char *initial = s;

	while (count < n)
	{
	*s++ = b;
	count++;
	}
	return (initial);
}
