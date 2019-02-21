#include "holberton.h"

/**
 * print_number - print an integer
 * @n: the integer
 */
void print_number(int n)
{
	int max = 1000000000;
	int digit;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	if (n < 0)
		_putchar('-');
	while (max > 0)
	{
		digit = n / max % 10;
		digit = digit > 0 ? digit : -digit;
		if (digit)
			_putchar(digit + '0');
		max /= 10;
	}
}
