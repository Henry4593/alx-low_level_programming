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
	int x = 0;
	int y;

	while (s[x] != '\0')/*iterates string s*/
	{
		for (y = 0; accept[y] != '\0'; y++) /* iterates target */
		{
			if (s[x] == accept[y]) /* match found */
			{
				s = &s[x];
				return (s);
			}
			x++;
		}
		return (NULL); /*no matches */
}
