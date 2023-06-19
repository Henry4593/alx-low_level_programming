#include "dog.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * free_dog - frees memory of struct dog and
 * its members
 *
 * @d: struct to be freed
 * Return: nothing to return
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
