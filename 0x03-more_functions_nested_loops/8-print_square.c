#include "holberton.h"

/**
 * print_square - print square made of # with given side lengths
 * @size: the side lengths, does nothing if zero or less
 */
void print_square(int size)
{
	int col, row;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			_putchar('#');
		_putchar('\n');
	}
}
