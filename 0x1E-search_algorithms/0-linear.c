#include "search_algos.h"
/**
 * linear_search - Locates target value in integer array
 * @array: Pointer to array to search
 * @size: Number of elements in the array
 * @value: Target value to locate
 *
 * Return: Index of found value, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t idx = 0;

	if (array == NULL)
		return (-1);
	for (; idx < size; idx++)
	{
		printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
		if (array[idx] == value)
			return (idx);
	}
	return (-1);
}

