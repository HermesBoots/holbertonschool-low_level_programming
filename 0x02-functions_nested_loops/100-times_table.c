#include "holberton.h"

/**
 * print_times_table - prints a times table for a given number
 * @n: which times table to print, min. 0 max. 15
 */
void print_times_table(int n)
{
	int col, product, row;

	if (n <= 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		_putchar('0');
		_putchar(',');
		_putchar(' ');
		for (col = 1; col <= n; col++)
		{
			product = row * col;
			if (product < 100)
				_putchar(' ');
			else
				_putchar(product / 100 + '0');
			if (product < 10)
				_putchar(' ');
			else
				_putchar(product / 10 % 10 + '0');
			_putchar(product % 10 + '0');
			if (col < n)
			{
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				_putchar('\n');
			}
		}
	}
}
