#include <stdio.h>

/**
 * main - A program that prints 0-9
 * separated with commas, using putchar
(*
 * Return: Always 0 (Success)
 */

int main(void)
{
	int num_ = '0';

	while (num_ <= '9')
	{
		putchar(num_);
		if (num_ != '9')
		{
			putchar(',');
			putchar(' ');
		}
		num_++;
	}
	putchar('\n');

	return (0);
}
