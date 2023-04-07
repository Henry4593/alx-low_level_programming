#include "main.h"
#define NULL 0

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search from
 * @accept: target is matched
 * Return: points to index of string at 1st occurence
 */

char *_strpbrk(char *s, char *accept)
{
	int x = 0, y;

	while (s[x] != '\0')/*iterates string s*/
	{
		for (x = 0; s[x] != '\0'; x++)
		{
			for (y = 0; accept[y] != '\0'; y++)
			{
				if (s[x] == accept[y])
					return (s + x);
			}
		}
	}
	return (NULL);
}
