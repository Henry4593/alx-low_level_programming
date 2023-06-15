#include <stdlib.h>
#include "main.h"
#include <stddef.h>
/**
 * *array_range - creates an array of integers.
 * @min: smallest number
 * @max: largest number
 *
 * Return: pointer to allocated memory,
 * NULL if min > max or no memory allocated
 */

int *array_range(int min, int max)
{
	int *alloc_mem;
	int len, index, num;

	if (min > max)
		return (NULL);
	len = (max - min) + 1;

	alloc_mem = malloc(sizeof(int) * len);

	if (alloc_mem == NULL)
		return (NULL);

	for (num = min, index = 0; num <= max; index++, num++)
		*(alloc_mem + index) = num;

	return (alloc_mem);
}
