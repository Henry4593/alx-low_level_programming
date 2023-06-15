#include <stdlib.h>
#include "main.h"
#include <stddef.h>

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory previously allocated with a
 * call to `malloc : malloc(old_size)`
 * @old_size: size in bytes allocated for ptr.
 * @new_size: size in bytes allocated for new memory block.
 *
 * Return: pointer to new memory block, NULL(failed allocation)
 * or ptr(retained memory).
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_alloc_mem;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if ((new_size == 0) && (ptr != NULL))
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_alloc_mem = malloc(new_size);
		if (new_alloc_mem == NULL)
			return (NULL);
	}
	if (new_size > old_size && (ptr != NULL))
	{
		new_alloc_mem = malloc(new_size);
		if (new_alloc_mem == NULL)
			return (new_alloc_mem);
		for (i = 0; i < old_size; i++)
			new_alloc_mem[i] = *((char *)ptr + 1);
		free(ptr);
	}

	return (new_alloc_mem);
}
