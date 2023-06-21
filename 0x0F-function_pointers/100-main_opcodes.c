#include <stdlib.h>
#include <stdio.h>

/**
 * main - a program that prints
 * its own opcodes
 *
 * @argc: arguments count
 * @argv: argument's vector
 * Return: (0) success
 */

int main(int argc, char *argv[])
{
	int y, (*arr)(int, char **) = main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}
	printf("%.2x", *(unsigned char *)arr);
	arr++;
	for (y = 1; y < atoi(argv[1]); y++)
	{
		printf(" %.2x", *(unsigned char *)arr);
		arr++;
	}
	printf("\n");
	return (0);
}
