#include "main.h"

/**
 * _strspn - Gets length of prefix substring
 * @s: String to search
 * @accept: Prefix to match
 *
 * Description: Returns number of bytes in initial
 * segment of s which consist only of bytes from accept.
 *
 * Return: Number of bytes in s which consist only of bytes from accept.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int idx_i, idx_j, n;

	n = 0;
	for (idx_i = 0; s[idx_i] != '\0'; idx_i++)
	{
		for (idx_j = 0; accept[idx_j] != '\0'; idx_j++)
			if (s[idx_i] == accept[idx_j])
				n++;
		if (idx_i == n)
			break;
	}
	return (idx_i);
}
