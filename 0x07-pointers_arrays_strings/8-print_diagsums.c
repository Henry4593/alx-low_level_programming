#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of
 * a 2-D matrix
 *
 * @a: array of the matrix
 * @size: size of the matrix
 * Return: void (nothing to return)
 */
void print_diagsums(int *a, int size)
{
	int i, diag_sum1 = 0, diag_sum2 = 0;

	for (i = 0; i < size; i++)
	{
		diag_sum1 += a[i * size + i];
		diag_sum2 += a[(i + 1) * size - i - 1];
	}
	printf("%d, %d\n", diag_sum1, diag_sum2);
}
