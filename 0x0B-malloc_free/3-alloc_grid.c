#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * alloc_grid -  returns a pointer to a
 * 2 dimensional array of integers.
 * @width: width of the grid
 * @height: height of the grid
 * Return: NULL(failure),pointer 2-D integer
 * array
 */

int **alloc_grid(int width, int height)
{
	int **arr;
	int index, i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	arr = (int **)malloc(width * sizeof(int *));

	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	for (index = 0; index < width; index++)
	{
		*(arr + index) = (int *)malloc(height * sizeof(int));

		if (*(arr + index) == NULL)
		{
			for (i = 0; i < index; i++)
			{
				free(*(arr + i));
			}
			free(arr);
			return (NULL);
		}

	}
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
			*(*(arr + i) + j) = 0;
	}
	return (arr);
}
