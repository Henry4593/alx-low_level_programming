#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * in an array
 * @array: array that contains int elements to be
 * searched
 * @size: size of the array
 * @cmp: pointer to the function used to compare values
 * Return: (-1) empty array or no match found.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int y;

	if (array && cmp && size > 0)
		for (y = 0; y < size; y++)
			if (cmp(array[y]))
				return (y);
	return (-1);
}
