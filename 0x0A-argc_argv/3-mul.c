#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - a program that multiplies two numbers.
 * @argc: counts number of arguments
 * @argv: the arguments
 * Return: 0 always success, 1 on error encounter
 */

int main(int argc, char *argv[])
{
	int result, num1, num2;

	if (argc != 3)
	{

		printf("Error\n");
		return (1);
	}
	else
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		result = num1 * num2;

		printf("%d\n", result);
	}
	return (0);
}
