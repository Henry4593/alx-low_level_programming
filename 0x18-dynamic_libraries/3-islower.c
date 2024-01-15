#include "main.h"

/**
 * _islower - Checks if a character is lowercase
 * @c: The character to check
 *
 * Description: Checks if c is between ASCII values
 * 97-'a' and 122-'z' to determine if lowercase.
 *
 * Return: 1 if lowercase, 0 otherwise
 */

int _islower(int c)
{
	if ((c >= 97) && (c <= 122))
		return (1);
	else
		return (0);
}
