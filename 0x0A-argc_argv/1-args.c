#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: arguments count
 * @argv: array of arguments
 * Return: 0 alway success
 */

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		argc = 0;
		printf("%d\n", argc);
	}
	else
		printf("%d\n", argc - 1);
}
