#include <stdio.h>

/**
 * main - Entry point, prints sum of multiples of 3 or 5 less than 1024
 *
 * Return: 0
 */
int main(void)
{
	int i;
	int max = 1024;
	int sum = 0;

	for (i = 3; i < max; i++)
	{
		if (i % 3 == 0)
			sum += i;
		else if (i % 5 == 0)
			sum += i;
	}
	printf("%d\n", sum);
	return (0);
}
