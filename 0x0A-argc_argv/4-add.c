#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * isNumber - loops through each argv to check if it's numerical.
 * @argv_ptr: points to argv
 * Return: 1 true(its a number), 0 false
 */

bool isNumber(char *argv_ptr)
{
	int x = 0;

	for (x = 0; argv_ptr[x]; x++)
	{
		if (!(argv_ptr[x] >= '0' && argv_ptr[x] <= '9'))
			return (0);
	}
	return (1);
}

/**
 * main - print sum, if provided arguments are numerical
 * @argc: counts arguments
 * @argv: provided arguments
 * Return: 0 (success),1 if argument(s) are non-numerical
 */

int main(int argc, char *argv[])
{
	int x = 1;
	int sum = 0;


	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	while (x < argc)
	{
		if (isNumber(argv[x]))
			sum = sum + atoi(argv[x]);
		else
		{
			printf("Error\n");
			return (1);
		}
		x++;
	}
	printf("%d\n", sum);

	return (0);
}
