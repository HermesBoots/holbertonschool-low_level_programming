#include "holberton.h"

/**
 * print_diagonal - print a diagonal line using back slashes
 * @n: number of terminal rows to span the line across
 */
void print_diagonal(int n)
{
	int lines, spaces;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (lines = 0; lines < n; lines++)
	{
		for (spaces = 0; spaces < lines; spaces++)
			_putchar(' ');
		_putchar('\\');
		_putchar('\n');
	}
}
