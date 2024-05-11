#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array using Binary Search.
 * @array: Pointer to the sorted array to search.
 * @lo: Lower bound of the search range
 * @hi: Upper bound of the search range
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
int _binary_search(int *array, size_t lo, size_t hi, int value)
{
	size_t pos;

	if (array == NULL)
		return (-1);

	while (hi >= lo)
	{
		printf("Searching in array: ");
		for (pos = lo; pos < hi; pos++)
			printf("%d, ", array[pos]);
		printf("%d\n", array[pos]);

		pos = lo + (hi - lo) / 2;
		if (array[pos] == value)
			return (pos);
		if (array[pos] > value)
			hi = pos - 1;
		else
			lo = pos + 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array using jumps.
 * @array: Pointer to the sorted array to search.
 * @size: Number of elements in the array.
 * @value: Target value to search for.
 *
 * Return: The index of the first occurrence of the value, or -1 if not found.
 *
 * Description: Implements a galloping search (exponential jumps) to locate a
 * potential range for the target value, followed by a binary search within
 * that range.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t pos = 0, hi;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (pos = 1; pos < size && array[pos] <= value; pos = pos * 2)
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
	}

	hi = pos < size ? pos : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", pos / 2, hi);
	return (_binary_search(array, pos / 2, hi, value));
}
