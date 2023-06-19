#include "dog.h"
#include <stddef.h>
/**
 * init_dog - initialize a variable of type struct dog
 * @d: points to struct dog
 * @name: name attribute of dog
 * @age: age attribute of dog
 * @owner: owner attribute of dog
 *
 * Description: name,age,owner are members of struct dog
 *
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
