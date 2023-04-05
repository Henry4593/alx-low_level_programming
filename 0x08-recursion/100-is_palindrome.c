#include "main.h"

/**
 * is_palindrome - returns 1 if a string
 * is a palindrome and 0 if it is not
 *
 * @s: string
 * Return: int
 */
int is_palindrome(char *s)
{
	int length = _strlen_recursion(s), x = 0;

	if (length == 0)
		return (1);
	return (assert_palindrome(s, length - 1, x));
}

/**
 * _strlen_recursion - returns the length of a string
 *
 * @s: string to get length from
 * Return: int
 */
int _strlen_recursion(char *s)
{
	int length;

	if (*s == '\0')
		return (0);
	length = _strlen_recursion(s + 1);
			return (length + 1);
}

/**
 * assert_palindrome - returns 1 if palindrome,0 if not
 *
 * @s: string
 * @length: length of string
 * @x: counter
 * Return: int
 */
int assert_palindrome(char *s, int length, int x)
{
	if (length == x)
		return (1);
	else if (s[length] != s[x])
		return (0);
	if (x < length)
		return (assert_palindrome(s, --length, ++x));
	return (1);
}
