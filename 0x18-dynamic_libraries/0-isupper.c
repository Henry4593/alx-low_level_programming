#include "main.h"

/**
 * _isupper - Checks if a character is uppercase
 * @c: The character to check
 *
 * Description: Checks if c is between ASCII values 65-'A' and 90-'Z'
 * to determine if it is uppercase.
 *
 * Return: 1 if uppercase, 0 otherwise
*/

int _isupper(int c)
{
	if ((c >= 65) && (c <= 90))
		return (1);
	else
		return (0);
}
