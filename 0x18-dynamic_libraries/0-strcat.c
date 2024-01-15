#include "main.h"
#include <stdio.h>

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string to append to dest
 *
 * Description: Appends src string to dest string overwriting
 * the terminating null byte at the end of dest, and then
 * adds a terminating null byte.
 *
 * Return: Pointer to resulting concatenated string dest
*/

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int n = 0;

	while (dest[n] != '\0')
		n++;
	dest[n - 1] = ' ';
	for (; src[i] != '\0'; i++)
		dest[n + i] = src[i];
	dest[n + i] = '\0';
	return (dest);
}
