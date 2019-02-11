#include <stdio.h>
#include "holberton.h"

/**
 * print_to_98 - prints numbers between a starting point and 98
 * @n: the starting number
 */
void print_to_98(int n)
{
	int direction;

	direction = (n < 98) - (n > 98);
	for (; n != 98; n += direction)
		printf("%d, ", n);
	printf("%d\n", 98);
}
