#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point, prints last digit of random number at compares it to 5
 *
 * Return: 0
 */
int main(void)
{
	int digit, n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	digit = n % 10;
	if (digit == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, digit);
	}
	else if (digit > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, digit);
	}
	else if (digit < 6)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, digit);
	}
	return (0);
}
