#include <unistd.h>
#include "main.h"

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
 (*
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * print_alphabet - prints lowercase alphabets
  *
  */
void print_alphabet(void)
{
	char alpha;

	alpha = 'a';

	while (alpha <= 'z')
	{
		_putchar(alpha);
		alpha++;
	}
	_putchar('\n');
}

/**
 * _abs - compute absolute value of integer
 * @n: integer argument
 * Return: absolute value
 */

int _abs(int n)
{
	if (n > 0)
		return (n);
	else if (n < 0)
		return (-n);

	return (0);
}
