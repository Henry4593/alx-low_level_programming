#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search from
 * @accept: target is matched
 * Return: number of bytes for the matched
 */

unsigned int _strspn(char *s, char *accept)
{
	int a;
	int have_char = 0;
	int prev_char;

	while (*s)
	{
		a = 0;
		prev_char = have_char;
		while (*(accept + a) != '\0')
		{
			if (*(accept + a) == *s)
				have_char++;
			a++;
		}
		if (prev_char == have_char) /* not identical to char from accept */
			break;
		s++;
	}
	return (have_char);
}
