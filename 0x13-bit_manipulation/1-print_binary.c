#include "holberton.h"


/**
 * print_binary - print binary representation of integer
 * @n: number to print
 */
void print_binary(unsigned long int n)
{
	unsigned char leading = 1;
	unsigned long int mask = 0x8000000000000000ul;

	while (mask > 0)
	{
		switch (n & mask)
		{
		case 0:
			if (!leading)
				_putchar('0');
			break;
		default:
			_putchar('1');
			leading = 0;
		}
		mask >>= 1;
	}
	if (n == 0)
		_putchar('0');
}
