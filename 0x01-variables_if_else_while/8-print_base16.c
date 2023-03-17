#include <stdio.h>

/**
 * main - a program that prints all the numbers of base 16 in lowercase
 * using putchar
(*
 * Return: Always 0 (Success)
 */

int main(void)
{
	int num_ = '0';
	int alpha_lower = 'a';

	while (num_ <= '9') /*prints 0-9*/
	{
		putchar(num_);
		num_++;
	}

	while (alpha_lower <= 'f') /*prints a-f*/
	{
		putchar(alpha_lower);
		alpha_lower++;
	}

	putchar('\n');

	return (0);
}
