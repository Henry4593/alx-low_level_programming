#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * @n: bytes to use from s2
 *
 * Return: pointer to new string, NULL (failure)
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len1, len2, index1, index2;

	if (s1 == 0)
		s1 = "";
	if (s2 == 0)
		s2 = "";
	len1 = 0;
	while (*(s1 + len1))
		len1++;
	len2 = 0;
	while (*(s2 + len2))
		len2++;
	if (n >= len2)
		n = len2;
	new_str = malloc(sizeof(char) * (len1 + n + 1));
	if (new_str == 0)
		return (0);
	for (index1 = 0; index1 < len1; index1++)
		*(new_str + index1) = *(s1 + index1);
	for (index2 = 0; index2 < n; index2++, index1++)
		*(new_str + index1) = *(s2 + index2);
	*(new_str + index1) = '\0';
	return (new_str);
}
