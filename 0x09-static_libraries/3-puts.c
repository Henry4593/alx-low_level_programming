#include "main.h"

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @s: string to print(alternatively char s[])
 */

void _puts(char *s)
{
	while (*s != '\0')
		_putchar(*s++);

	_putchar('\n');
}
