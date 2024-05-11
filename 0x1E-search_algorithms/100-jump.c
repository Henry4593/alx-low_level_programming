#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using Jump Search.
 * @array: Pointer to the sorted array to search.
 * @size: Number of elements in the array.
 * @value: Target value to search for.
 *
 * Return: The index of the first occurrence of the value in the search range,
 *         or -1 if not found.
 *
 * Description: This function implements the Jump Search algorithm to find
 * the first occurrence of a value in a sorted array. It uses the square root
 * of the array size as a jump step to quickly traverse the array and narrow
 * down the search range. The final linear search is then performed within the
 * narrowed range.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t idx, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (idx = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		idx = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", idx, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; idx < jump && array[idx] < value; idx++)
		printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
	printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);

	return (array[idx] == value ? (int)idx : -1);
}
