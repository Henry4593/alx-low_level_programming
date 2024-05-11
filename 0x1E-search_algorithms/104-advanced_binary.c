#include "search_algos.h"

/**
 * advanced_binary_recursive - Finds the first index of a value in a sorted
 * array.
 * @array: Pointer to the sorted array to search.
 * @left: Lower bound of the search range (inclusive).
 * @right: Upper bound of the search range (inclusive).
 * @value: Target value to search for.
 *
 * Return: The index of the first occurrence of the value in the search range,
 *         or -1 if not found.
 *
 * Description: This function performs a recursive binary search to find the
 * first occurrence of a value in a sorted array.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t pos;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (pos = left; pos < right; pos++)
		printf("%d, ", array[pos]);
	printf("%d\n", array[pos]);

	pos = left + (right - left) / 2;
	if (array[pos] == value && (pos == left || array[pos - 1] != value))
		return (pos);
	if (array[pos] >= value)
		return (advanced_binary_recursive(array, left, pos, value));
	return (advanced_binary_recursive(array, pos + 1, right, value));
}

/**
 * advanced_binary - Finds the first index of a value in a sorted array.
 * @array: Pointer to the sorted array to search.
 * @size: Number of elements in the array.
 * @value: Target value to search for.
 *
 * Return: The index of the first occurrence of the value in the array,
 *         or -1 if not found.
 *
 * Description: This function serves as a wrapper for the recursive
 * advanced_binary_recursive function. It checks for edge cases where the input
 * array is NULL or has size 0, and returns -1 in those cases. Otherwise, it
 * calls the recursive function with appropriate parameters.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
