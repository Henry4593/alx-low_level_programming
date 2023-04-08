#include <stdio.h>
#include "main.h"

/**
 * main - a program that prints its name,
 * followed by a new line.
 * @argc: argument/parameters count
 * @argv: array of arguments
 * Return: 0 always success
 */

int main(int argc, char *argv[])
{
	if (argc > 0)
		printf("%s\n", argv[0]);

	return (0);
}
