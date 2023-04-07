#include "main.h"

/**
 * _memcpy - A program that copies n bytes
 * from memory area src to memory area dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int count = 0;
	char *initial = dest;

	while (count < n)
	{
		*dest++ = *src++;
		count++;
	}
	return (initial);
}
