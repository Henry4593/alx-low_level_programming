#include "main.h"

/**
 * _puts - Prints a string to stdout
 * @str: The string to print
 *
 * Description: Prints each character of the string to stdout
 * followed by a new line. Iterates through the input string
 * using a while loop, printing each character with _putchar
 * until the null byte is reached.
 *
 */

void _puts(char *str)
{
	int idx_n = 0;

	while (str[idx_n] != '\0')
	{
		_putchar(str[idx_n]);
		idx_n++;
	}
	_putchar('\n');
}
