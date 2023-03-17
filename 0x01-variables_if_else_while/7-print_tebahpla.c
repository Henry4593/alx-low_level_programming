#include <stdio.h>

/**
 * main - prints lowercase alphabets in reversed order using putchar
 * Return: Always 0 (Success)
 */

int main(void)
{
	char alpha_lower = 'z';

	while (alpha_lower >= 'a')
	{
		putchar(alpha_lower);
		alpha_lower--;
	}
	putchar('\n');

	return (0);
}
