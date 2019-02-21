#include <stdio.h>

/**
 * print_buffer - print a buffer like a hex editor does
 * @buff: the buffer
 * @size: size of buffer
 */
void print_buffer(char *buff, int size)
{
	char val;
	int col, row;

	if (size <= 0)
		putchar('\n');
	for (row = 0; row < size; row += 10)
	{
		printf("%08x: ", row);
		for (col = 0; col < 10; col++)
		{
			if (row + col < size)
				printf("%02x", buff[row + col]);
			else
				printf("  ");
			if (col % 2 == 1)
				putchar(' ');
		}
		for (col = 0; col < 10 && row + col < size; col++)
		{
			val = buff[row + col];
			if (val >= ' ' && val <= '~')
				putchar(val);
			else
				putchar('.');
		}
		putchar('\n');
	}
}
