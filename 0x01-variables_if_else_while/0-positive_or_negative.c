#include <stdlib.h>
#include <time.h>


/**
  * main - a program that prints lines on the console,
  * whether a number is negative or positive or zero.
  * Return: 0 (program ran successfully)
  */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	else if (n < 0)
	{
		printf("%d is negative\n", n);
	}
	else
	{
		printf("%d is positive\n", n);
	}
	return (0);
}
