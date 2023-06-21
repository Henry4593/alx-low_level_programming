#include "function_pointers.h"

/**
 * print_name - prints name using passed in
 * pointer to function
 * @name: string passed in
 * @f: pointer to the function
 * Return: nothing
 *
 */

void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}
