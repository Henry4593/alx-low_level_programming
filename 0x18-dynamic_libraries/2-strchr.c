#include "main.h"
#include <stdio.h>

/**
 * _strchr - Locates first occurrence of character in string
 * @s: The string to search
 * @c: Character to locate
 *
 * Description: Searches string s for first occurrence of c.
 * Returns pointer to location of c in s or NULL if not found.
 *
 * Return: Pointer to first occurrence of c or NULL
 */

char *_strchr(char *s, char c)
{
	unsigned int idx_i = 0;

	for (idx_i = 0; s[idx_i] != '\0'; idx_i++)
		if (s[idx_i] == c)
			return (&s[idx_i]);
	if (s[idx_i] == c)
		return (&s[idx_i]);
	else
		return (0);
}
