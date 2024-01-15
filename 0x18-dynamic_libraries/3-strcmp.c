#include "main.h"
#include <stdio.h>

/**
 * _strcmp - Compares two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Description: Compares strings byte-by-byte until
 * null byte or difference is found.
 * Returns 0 if identical, difference of first
 * differing bytes if different.
 *
 * Return: Integer difference of first differing bytes or 0
 */

int _strcmp(char *s1, char *s2)
{
	int idx;

	for (idx = 0; s1[idx] != '\0' && s2[idx] != '\0'; idx++)
		if (s1[idx] - s2[idx])
			break;
	return (s1[idx] - s2[idx]);
}
