#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array using
 * interpolation.
 * @array: Pointer to the sorted array to search.
 * @size: Number of elements in the array.
 * @value: Target value to search for.
 *
 * Return: The index of the first occurrence of the value in the search range,
 *         or -1 if not found.
 *
 * Description: This function implements the Interpolation Search algorithm
 * to find the first occurrence of a value in a sorted array.
 * It uses interpolation to estimate the possible position of the
 * target value based on its value and the values of the endpoints
 * of the search range. This estimated position is then used to
 * refine the search further.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, lo, hi;

	if (array == NULL)
		return (-1);

	for (lo = 0, hi = size - 1; hi >= lo;)
	{
		pos = lo + (((double)(hi - lo) / (array[hi] - array[lo])) *
		(value - array[lo]));
		if (pos < size)
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}

		if (array[pos] == value)
			return (pos);
		if (array[pos] > value)
			hi = pos - 1;
		else
			lo = pos + 1;
	}

	return (-1);
}
