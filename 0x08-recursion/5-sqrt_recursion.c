#include "main.h"

/**
 * find_root - find square root of number n,
 * starting from the smallest possible number (0).
 * @n: number provided
 * @root: test this root
 * Return: number if naturally it's a root, -1 if it is not
 */

int assert_root(int n, int root)
{
	if (root * root > n)
		return (-1);

	if (root * root == n)
		return (root);

	return (assert_root(n, root + 1));
}

/**
 * _sqrt_recursion - find natural square root of 
 * the number n
 * @n: number n
 * Return: natural square root, or -1 if it is not.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (assert_root(n, 0));
}
