#include "dog.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_dog - prints struct dog
 * @d: points to memory location of
 * variable d of struct dog
 *
 * Return: NULL(failed memory allocation)
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", d->name != NULL ? d->name : "(nil)");
		printf("Age: %f\n", d->age);
		printf("Owner: %s\n", d->owner != NULL ? d->owner : "(nil)");
	}
}
