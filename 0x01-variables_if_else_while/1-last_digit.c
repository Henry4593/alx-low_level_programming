#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 *main - a program that print lines to the console;
 *the number,the last digit and indicates whether
 *the last digit is 0,greater than 5 and less
 *than six but not zero
(*
 *Return: Always 0 (Success)
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("Last digit of %i is %i and is ", n, (n % 10));

	if ((n % 10) == 0)
	{
		printf("0\n");
	}
	else if ((n % 10) > 5)
	{
		printf("greater than 5\n");
	}
	else
	{
		printf("less than 6 and not 0\n");
	}

	return (0);
}
