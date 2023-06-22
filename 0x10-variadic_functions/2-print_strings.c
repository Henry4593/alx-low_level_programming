#include "variadic_functions.h"

/**
 * print_strings - prints strings
 * @separator: character that separates the strings
 * @n: number of arguments
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int y;
	char *str;

	va_list arg_list;

	va_start(arg_list, n);

	for (y = 0; y < n; y++)
	{
		str = va_arg(arg_list, char *);
		if (!str)
			str = "(nil)";
		if (!separator)
			printf("%s", str);
		else if (separator && y == 0)
			printf("%s", str);
		else
			printf("%s%s", separator, str);
	}

	printf("\n");

	va_end(arg_list);
}
