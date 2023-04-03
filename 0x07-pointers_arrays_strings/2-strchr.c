#include "main.h"
#define NULL 0

/**
 * _strchr - locates a character in a string
 * @s: string to search from
 * @c: the targeted character
 * Return: pointer to the targeted character
 */

char *_strchr(char *s, char c)
{
	int a = 0;

	while (*(s + a))
	{
		if (*(s + a) == c)
		return (s + a);
		a++;
	}
	if (*(s + a) == c)
		return (s + a);
	return (NULL);
}

