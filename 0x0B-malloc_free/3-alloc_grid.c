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
		return (0);
	arr = (int **)malloc(sizeof(int *) * height);
	if (arr == 0)
	{
		for (i = height - 1; i >= 0; i--)
		{
		free(*(arr + i));
		}
		arr = NULL;
		return (0);
	}
	for (index = 0; index < height; index++)
	{
		*(arr + index) = (int *)malloc(sizeof(int) * width);
		if (*(arr + index) == 0)
		{
			for (i = width - 1; i >= 0; i--)
				free(*(arr + i));
			free(arr);
			arr = NULL;
			return (0);
		}
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			*(*(arr + i) + j) = 0;
	}
	return (arr);
}
