#include "main.h"
#include <stdio.h>

/**
 * _strncpy - Copies a string with specified number of bytes
 * @dest: Destination buffer to copy string to
 * @src: Source string to copy
 * @n: Maximum number of bytes to copy from src
 *
 * Description: Copies n bytes from src into dest, padding
 * the remainder of dest with null bytes if src contains
 * less than n characters.
 *
 * Return: Pointer to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int idx = 0;

	for ( ; idx < n && src[idx] != '\0'; idx++)
		dest[idx] = src[idx];
	for ( ; idx < n ; idx++)
		dest[idx] = '\0';
	return (dest);
}
