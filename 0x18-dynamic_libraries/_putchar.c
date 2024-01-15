#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Description: Writes the character @c to stdout
 * using write system call.
 *
 * Return: On success - returns character written
 * On error - returns -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
