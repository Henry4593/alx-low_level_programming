#include "main.h"

/**
 * _memcpy - Copies memory area
 * @dest: Destination memory area to copy to
 * @src: Source memory area to copy from
 * @n: Number of bytes to copy
 *
 * Description: Copies n bytes from memory area src to
 * memory area dest. The memory areas should not overlap.
 *
 * Return: Pointer to dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int idx;

	for (idx = 0; idx < n; idx++)
		dest[idx] = src[idx];

	return (dest);
}
