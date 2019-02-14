#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point, prints sum of even Fibonnaci numbers that are < 4000000
 *
 * Return: 0
 */
int main(void)
{
	unsigned long current = 1, new, previous = 1, sum = 0;

	while (current < 4000000)
	{
		if (current % 2 == 0)
			sum += current;
		new = current + previous;
		previous = current;
		current = new;
	}
	printf("%lu\n", sum);
	return (0);
}
