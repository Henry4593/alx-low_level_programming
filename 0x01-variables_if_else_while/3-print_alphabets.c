#include <stdio.h>

/**
 *main - prints lowercase and uppercase a-zA-Z using putchar
 *Return: Always 0 (Success)
 */

int main(void)
{
	char alpha_lower = 'a';
	char alpha_upper = 'A';

	while (alpha_lower <= 'z') /*print lowercases a-z*/
	{
		putchar(alpha_lower);
		alpha_lower++;
	}

	while (alpha_upper <= 'Z') /*print uppercase A-Z*/
	{
		putchar(alpha_upper);
		alpha_upper++;
	}

	putchar('\n');

	return (0);
}
