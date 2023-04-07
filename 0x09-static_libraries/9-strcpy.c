#include "main.h"
/**
 * _strcpy - Copies the string from param 'src',
 * including the terminating null byte ('\0'),
 * to the buffer 'dest'.
(*
 * @dest: where the string is copied.
 * @src: string to be copied.
 *
 * Return: the string 'dest'.
 */
char *_strcpy(char *dest, char *src)
{
	int length = 0;

	while (src[length] != '\0')
	{
		length++;  /* count the length of the source string*/
	}
	for (int x = 0; x < length; x++)
	{
		dest[x] = src[x];  /* copy the characters from source to destination*/
	}
	dest[length] = '\0';  /* add '\0' at the end of the destination string*/
	return (dest);
}
