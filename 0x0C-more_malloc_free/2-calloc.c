#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _calloc - allocates memory for an array, using malloc
 *
 * @nmemb: elements of the array
 * @size: size bytes of each element
 * Return: pointer to allocated memory,NULL (failure)
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *alloc_mem;

	if (nmemb == 0 || size == 0)
		return (NULL);
	alloc_mem = malloc(nmemb * size);
	if (alloc_mem == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		alloc_mem[i] = 0;
	return (alloc_mem);
}
