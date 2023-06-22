#include "variadic_functions.h"

/**
 * print_numbers - prints numbers passed as
 * arguments/parameter to the function,followed by a line
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int y;
	va_list arg_list;

	va_start(arg_list, n);

	for (y = 0; y < n; y++)
	{
		if (!separator)
			printf("%d", va_arg(arg_list, int));
		else if (separator && y == 0)
			printf("%d", va_arg(arg_list, int));
		else
			printf("%s%d", separator, va_arg(arg_list, int));
	}

	va_end(arg_list);

	printf("\n");
}
