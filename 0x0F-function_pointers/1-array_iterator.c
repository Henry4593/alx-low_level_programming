#include "function_pointers.h"

/**
 * array_iterator - executes a function given as
 * a parameter on each element of an array
 *
 * @array: passed in array
 * @size: size of the array
 * @action: function that executes each element of the array
 * Return: nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int y;

	if (array && size > 0 && action)
	{
		for (y = 0; y < size; i++)
			action(array[y]);
	}
}
