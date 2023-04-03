#include "main.h"

/**
 * set_string - sets the value of a pointer to a char.
 *
 * @s: a pointer to pointer of type char
 * @to: pointer to type char
 * Return: void(nothing to return)
 */
void set_string(char **s, char *to)
{
		*s = to;
}
