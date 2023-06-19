#include <stdlib.h>
#include <stddef.h>
#include "dog.h"

/**
 * new_dog - an element of struct dog
 * @name: attribute/member of new_dog
 * @age: attribute/member of new_dog
 * @owner: attribute/member of new_dog
 *
 * Return: NULL(failed memory allocation),
 * memory location for new_dog
 *
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *new_dog_name, *new_dog_owner;

	new_dog = malloc(sizeof(dog_t));
		if (new_dog == NULL)
			return (new_dog);
	new_dog_name = malloc(sizeof(name));
		if (new_dog_name == NULL)
		{
			free(new_dog);
			return (NULL);
		}
	new_dog_owner = malloc(sizeof(owner));
	if (new_dog_owner == NULL)
	{
		free(new_dog_name);
		free(new_dog);
		return (NULL);
	}
	_strcpy(new_dog_name, name);
	_strcpy(new_dog_owner, owner);
	new_dog->name = new_dog_name;
	new_dog->owner = new_dog_owner;
	new_dog->age = age;
	return (new_dog);
}

/**
 * _strcpy - copies string to given memory location
 * @dest: memory location where the provided string
 * is copied
 * @src: the string to be copied
 *
 * Return: array of char
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0;

	while (*(src + len) != '\0')
	{
		*(dest + len) = *(src + len);
		len++;
	}
	*(dest + len) = *(src + len);

	return (dest);
}
