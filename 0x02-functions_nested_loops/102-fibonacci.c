#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point, prints first 50 Fibonnaci numbers
 *
 * Return: 0
 */
int main(void)
{
	int i;
	unsigned long int current = 1, new, previous = 1;

	for (i = 0; i < 49; i++)
	{
		printf("%lu, ", current);
		new = previous + current;
		previous = current;
		current = new;
	}
	printf("%lu\n", current + previous);
	return (0);
}
