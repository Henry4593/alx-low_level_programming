#include "main.h"

/**
 * _strstr - Locates a substring in a string
 * @haystack: The string to search in
 * @needle: The substring to find
 *
 * Description: Finds the first occurrence of the substring needle
 * in the string haystack.
 *
 * Return: Pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *sub_string = needle;
		char *base_address = haystack;

		while (*haystack != '\0' && *sub_string != '\0' && *sub_string == *haystack)
		{
			sub_string++;
			haystack++;
		}
		if (*sub_string == '\0')
			return (base_address);
		haystack = base_address + 1;
	}
	return (0);
}
