#include "variadic_functions.h"

/**
 * sum_them_all - calculates the sum of all
 * the passed arguments/parameters
 * @n: total number of arguments passed to the function
 *
 * Return: sum total of the passed arguments
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list arg_list;

	va_start(arg_list, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg_list, int);
	}
	va_end(arg_list);

	return (sum);
}
