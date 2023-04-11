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
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);
	int **arr = malloc(height * sizeof(int *));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		arr[i] = malloc(width * sizeof(int));

		if (arr[i] == NULL)
		{
			while (--i >= 0)
			{
				free(arr[i]);
			}
			free(arr);
			return (NULL);
		}
		for (j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}
	return (arr);
}
