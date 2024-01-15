#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to search
 * @accept: Set of bytes to search for
 *
 * Description: Locates the first occurrence in the string s
 * of any of the bytes in the string accept.
 *
 * Return: Pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found.
 */

char *_strpbrk(char *s, char *accept)
{
	unsigned int idx_i, idx_j;

	for (idx_i = 0; s[idx_i] != '\0'; idx_i++)
		for (idx_j = 0; accept[idx_j] != '\0'; idx_j++)
			if (s[idx_i] == accept[idx_j])
				return (&s[idx_i]);
	return (0);
}
