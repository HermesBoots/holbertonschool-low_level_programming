#include "holberton.h"

/**
 * print_line - prints a given number of underscores
 * @n: the number to print, does nothing if below 0
 */
void print_line(int n)
{
	while (n-- > 0)
		_putchar('_');
	_putchar('\n');
}
