#include "holberton.h"

/**
 * more_numbers - print the numbers 0 to 14 ten times
 */
void more_numbers(void)
{
	int i, n;

	for (i = 0; i < 10; i++)
	{
		for (n = 0; n < 15; n++)
		{
			if (n >= 10)
				_putchar(n / 10 % 10 + '0');
			_putchar(n % 10 + '0');
		}
		_putchar('\n');
	}
}
