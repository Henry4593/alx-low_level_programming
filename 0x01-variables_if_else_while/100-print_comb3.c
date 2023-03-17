#include <stdio.h>

/**
 * main - prints 00 to 89 with no duplicate digits or combos:
 * Example: 01 or 10,11,22...
(*
 * Return: Always 0 (Success)
 */

int main(void)
{
	int ones;
	int tens;

	for (tens = '0'; tens <= '9'; tens++) /*incremment tens by 1*/
	{
		for (ones = (tens + 1); ones <= '9'; ones++) /*combines one's ten+1*/
		{
			putchar(tens);
			putchar(ones);

			if (tens != '8' || ones != '9') /*print commas and whitespaces*/
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
