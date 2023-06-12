#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory, which contains a copy
 * of the string given as a parameter.
 *
 * @str: pointer to the old string
 *
 * Return: pointer to the new string,
 * NULL (unsuccessful).
 */

char *_strdup(char *str)
{
	char *new_str;
	unsigned int size = 0, i;

	if (str == NULL)
		return (NULL);
	for (i = 0; *(str + i) != '\0'; i++)
		size++;

	new_str = malloc(sizeof(char) * (size + 1));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(new_str + i) = *(str + i);
	new_str[size] = '\0';

	return (new_str);
}
