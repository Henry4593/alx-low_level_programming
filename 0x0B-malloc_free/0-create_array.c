#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * create_array - create an array of chars
 * initialized with specific char.
 * @size: size of the array
 * @c: any provided char to be initialized
 * Return: NULL unsuccessful, arr pointer(success)
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;

	if (size == 0)
	{
		return (NULL);
	}
	else
	{
		char *arr = malloc(size * sizeof(char));

		if (arr == NULL)
			return (NULL);
		while (i < size)
		{
			*(arr + i) = c;
			i++;
		}
		return (arr);
	}
}
