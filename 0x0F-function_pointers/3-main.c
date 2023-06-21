#include "3-calc.h"

/**
 * main - performs simple
 * mathematical operations
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: (0) success.98,99,100 Error!
 */

int main(int argc, char *argv[])
{
	int a, b, result;

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if (!get_op_func(argv[2]) || argv[2][1] != '\0')
	{
		printf("Error\n");
		return (99);
	}
	if (b == 0 && (*argv[2] == '/' || *argv[2] == '%'))
	{
		printf("Error\n");
		return (100);
	}
	result = get_op_func(argv[2])(a, b);
	printf("%d\n", result);
	return (0);
}
