#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - a program that prints the minimum number
 * of coins to make change for an amount of money.
 *
 * @argc: counts arguments
 * @argv: the arguments
 * Return: 0 always success, 1 error occured
 */

int main(int argc, char *argv[])
{
	int i, cents, zero, cents_num, len;
	int coin_values[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	if (cents < 0)
	{
		zero = 0;
		printf("%d\n", zero);
		return (0);
	}

	cents = atoi(argv[1]);
	i = 0;

	cents_num = 0;
	len = sizeof(coin_values) / sizeof(int);

	for (i = 0; i < len; i++)
	{
		cents_num += cents / coin_values[i];
		cents = cents % coin_values[i];
	}
	printf("%d\n", cents_num);
	return (0);
}
