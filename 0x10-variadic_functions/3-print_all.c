#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * i.e types like char,int,float
 */

void print_all(const char * const format, ...)
{
	int y = 0;
	char *str, *separator = "";

	va_list arg_list;

	va_start(arg_list, format);

	if (format)
	{
		while (format[y])
		{
			switch (format[y])
			{
				case 'c':
					printf("%s%c", separator, (char) va_arg(arg_list, int));
					break;
				case 'i':
					printf("%s%d", separator, va_arg(arg_list, int));
					break;
				case 'f':
					printf("%s%f", separator, (float) va_arg(arg_list, double));
					break;
				case 's':
					str = va_arg(arg_list, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", separator, str);
					break;
				default:
					y++;
					continue;
			}
			separator = ", ";
			y++;
		}
	}

	printf("\n");
	va_end(arg_list);
}
