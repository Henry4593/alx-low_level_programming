#include "main.h"

/**
 * _strcpy - Copies a string from source to destination
 * @dest: The destination buffer
 * @src: The source string
 *
 * Description: Copies the string pointed to by src, including the
 * null terminator, to the buffer pointed to by dest.
 *
 * Return: Pointer to the destination buffer.
 */

char *_strcpy(char *dest, char *src)
{
	int idx = 0;

	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	/*dest[++idx] = '\n';*/
	return (dest);
}
