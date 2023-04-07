#include "main.h"
#define NULL 0

/**
 * _strstr -  locates a substring.
 * @haystack: string to search from
 * @needle: targeted substring
 * Return: A reference to the position within
 * the string where the complete substring first appears.
 */

char *_strstr(char *haystack, char *needle)
{
	int x = 0, y, z;

	if (needle[0] == '\0')
		return (haystack);

	while (haystack[x] != '\0')/*Traverse the characters in the haystack string*/
	{
	/*Iterate through "needle" on a match with the first character of "haystack"*/
		if (haystack[x] == needle[0])
		{
			z = x, y = 0;
			while (needle[y] != '\0')
			{
				if (haystack[z] == needle[y])
				{
					z++, y++;
				}
				else
				{
					break;
				}
			}
			if (needle[y] == '\0')
			{
				return (haystack + x);
			}
		}
		x++;
	}
	return (NULL);/*no matches found8*/
}
