#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * argstostr - A program that concatenates all arguments of the program.
 * @ac: argument counts.
 * @av: array of the arguments passed.
 * Return: NULL (failure), Pointer to the new string.
 */

char *argstostr(int ac, char **av)
{
	int x, y, z, size;
	char *arg_concat;

	size = 0;
	z = 0;
	if (ac == 0 || av == NULL)
		return (NULL);
	x = 0;
	while (x < ac)
	{
		y = 0;
		while (av[x][y])
		{
			size++;
			y++;
		}
		size++;
		x++;
	}
	arg_concat = malloc((sizeof(char) * size) + 1);
	if (arg_concat == NULL)
		return (NULL);
	x = 0;
	while (x < ac)
	{
		y = 0;
		while (av[x][y])
		{
			arg_concat[z] = av[x][y];
			y++;
			z++;
		}
		arg_concat[z] = '\n';
		z++;
		x++;
	}
	arg_concat[z] = '\0';
	return (arg_concat);
}
