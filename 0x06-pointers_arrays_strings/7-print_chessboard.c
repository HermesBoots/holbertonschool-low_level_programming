#include "holberton.h"

/**
 * print_chessboard - print an 8-by-8 grid
 * @a: array to print
 */
void print_chessboard(char (*a)[8])
{
	int x, y;

	for (y = 0; y < 8; y++)
	{
		for (x = 0; x < 8; x++)
		{
			_putchar(a[y][x]);
			if (x == 7)
				_putchar('\n');
		}
	}
}
