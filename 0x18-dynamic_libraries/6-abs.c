#include "main.h"

/**
 * _abs - Computes the absolute value of an integer
 * @n: The integer to compute the absolute value of
 *
 * Description: Computes the absolute value of the integer n.
 *
 * Return: The absolute value of n.
 */

int _abs(int n)
{
	if (n == 0)
		return (0);
	else if (n > 0)
		return (n);
	else
		return (-n);
}
