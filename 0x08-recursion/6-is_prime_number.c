#include "main.h"

/**
 * is_prime_number - returns 1 if prime number,
 * (0) if not prime
 *
 * @n: number provided
 * Return: recursion of function call
 */
int is_prime_number(int n)
{
	int x = 2;

	if (n <= 2)
		return (n == 2 ? 1 : 0);
	if (n % 2 == 0)
		return (0);
	return (is_prime(n, x));
}

/**
 * is_prime - returns 1 if the input integer is a
 * prime number, otherwise returns 0
 *
 * @n: number
 * @x: divisor
 * Return: int
 */
int is_prime(int n, int x)
{
	if (n != x && n % x == 0)
		return (0);
	else if (n == x)
		return (1);
	return (is_prime(n, x + 1));
}
