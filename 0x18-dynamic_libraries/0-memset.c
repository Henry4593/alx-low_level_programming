#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 * @s: Pointer to memory area to fill
 * @b: Value to fill memory area with
 * @n: Number of bytes to fill
 *
 * Description: Fills the first n bytes of memory area
 * pointed to by s with the constant value b.
 *
 * Return: Pointer to the filled memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
