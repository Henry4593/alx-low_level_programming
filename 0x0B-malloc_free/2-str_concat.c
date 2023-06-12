#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
  * str_concat - concatenates two strings
  * @s1: first string
  * @s2: second string
  * Return: NULL(error),pointer to new_str
  */

char *str_concat(char *s1, char *s2)
{
	unsigned int i = 0, j, size = 0;
	char *new_str;

	if (s1 != NULL)
		for (i = 0; *(s1 + i) != '\0'; i++)
			size++;
	if (s2 != NULL)
		for (i = 0; *(s2 + i) != '\0'; i++)
			size++;

	new_str = malloc(sizeof(char) * (size + 1));

	if (new_str == NULL)
		return (NULL);

	if (s1 == NULL && s2 == NULL)
	{
		*(new_str + 0) = '\0';
		return (new_str);
	}

	if (s1 != NULL)
	{
		for (i = 0; *(s1 + i) != '\0'; i++)
			*(new_str + i) = *(s1 + i);
	}

	if (s1 == NULL)
		i = 0;

	if (s2 != NULL)
		for (j = 0; *(s2 + j) != '\0'; j++)
		{
			*(new_str + i) = *(s2 + j);
			i++;
		}
	*(new_str + size) = '\0';

	return (new_str);
}
