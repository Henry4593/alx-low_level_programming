#include <unistd.h>
#include "main.h"

/**
 * _putchar - prints a character to the stdout
 *
 */

void _putchar(char c)
{
	write(1, &c, 1);
}
