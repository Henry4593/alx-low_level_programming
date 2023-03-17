#include <stdio.h>

/**
  * main - a program that prints lowercase alpha a-z
  * except lowercase alpha 'q' and 'e'
 (*
 * Return: 0 (success)
 */

int main(void)
{
	char alpha_lower = 'a';

	while (alpha_lower <= 'z')
	{
		if ((alpha_lower != 'q') && (alpha_lower != 'e'))
		{
			putchar(alpha_lower);
		}
		alpha_lower++;
	}
	putchar('\n');

	return (0);
}
