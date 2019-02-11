#include "holberton.h"

/**
 * times_table - print the 9 times table
 */
void times_table(void)
{
	int col, product, row;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			product = row * col;
			if (product < 10)
				_putchar(' ');
			else
				_putchar(product / 10 + '0');
			_putchar(product % 10 + '0');
			if (col < 9)
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
