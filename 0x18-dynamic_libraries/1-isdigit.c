#include "main.h"

/**
 * _isdigit - Checks if a character is a digit 0-9
 * @c: The character to check
 *
 * Description: Checks if c is between ASCII values 48-'0' and 57-'9'
 * to determine if it is a numeric digit character.
 *
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}
