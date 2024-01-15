#include "main.h"
#include <stdio.h>

/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: The destination string
 * @src: The source string to append to dest
 * @n: The maximum number of bytes to concatenate from src
 *
 * Description: Appends at most n bytes from src to dest, overwriting
 * the terminating null byte at the end of dest, and adding a new
 * terminating null byte at end.
 *
 * Return: A pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int x = 0;
	int j = 0;

	while (dest[j] != '\0')
		j++;
	for (; x < n && src[x] != '\0'; x++)
		dest[j + x] = src[x];
	dest[j + x] = '\0';
	return (dest);
}
