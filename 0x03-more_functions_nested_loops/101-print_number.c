#include "holberton.h"

/**
 * print_number - print a number without printf
 * @n: the number to print
 */
void print_number(int n)
{
	int divisor, quotient;

	if (n < 0)
		_putchar('-');
	for (divisor = 1000000000; divisor >= 10; divisor /= 10)
	{
		quotient = n / divisor;
		quotient = quotient > 0 ? quotient : -quotient;
		if (quotient > 0)
			_putchar(quotient % 10 + '0');
	}
	n = n % 10;
	n = n > 0 ? n : -n;
	_putchar(n + '0');
}
