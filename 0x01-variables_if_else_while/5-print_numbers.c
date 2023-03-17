#include <stdio.h>

/**
 * main - prints 0 to 9 to console
 * Return: Always 0 (Success)
 */

int main(void)
{
	int num_ = 0;

	while (num_ < 10)
	{
		printf("%i", num_);
		num_++;
	}
	putchar('\n');

	return (0);
}
