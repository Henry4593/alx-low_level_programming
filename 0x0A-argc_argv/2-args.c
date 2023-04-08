#include <stdio.h>
#include "main.h"

/**
 * main -  a program that prints all arguments it receives.
 * @argc: counts number of arguments
 * @argv: the arguments
 * Return: 0 always success
 */

int main(int argc, char *argv[])
{
	int count = 0;

	while (count < argc)
	{
		printf("%s\n", argv[count++]);
	}
	return (0);
}
