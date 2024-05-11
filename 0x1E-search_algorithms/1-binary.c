#include "search_algos.h"
/**
 * binary_search - Searches for a value in a sorted array using Binary Search.
 * @array: Pointer to the sorted array to search.
 * @size: Number of elements in the array.
 * @value: Target value to search for.
 *
 * Return: The index of the first occurrence of the value in the search range,
 *         or -1 if not found.
 *
 * Description: This function implements the Binary Search algorithm to find
 * the first occurrence of a value in a sorted array. It repeatedly
 * divides the search range in half until the target value is found
 * or the search range becomes empty.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t lo = 0;
	size_t hi = size - 1;
	size_t idx = 0;

	if (!array)
		return (-1);
	while (lo <= hi)
	{
		int pos = lo + (hi - lo) / 2;

		printf("Searching in array:");
		for (; idx < hi; idx++)
		{
			printf(" %d,", array[idx]);
		}
		printf(" %d\n", array[idx]);
		if (array[pos] == value)
			return (pos);
		if (array[pos] < value)
		{
			lo = pos + 1;
			idx = lo;
		}
		if (array[pos] > value)
		{
			hi = pos - 1;
			idx = lo;
		}
	}
	return (-1);
}
