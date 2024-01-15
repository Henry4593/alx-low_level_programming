#include "main.h"
#include <stdio.h>

/**
 * _strlen - Returns the length of a string
 * @s: The string to get the length of
 *
 * Description: Iterates through each character of
 * the string counting each one until the
 * terminating null byte is reached.
 *
 * Return: The length of the string s.
 */

int _strlen(char *s)
{
	int idx_n = 0;

	while (s[idx_n] != '\0')
		idx_n++;
	return (idx_n);
}
