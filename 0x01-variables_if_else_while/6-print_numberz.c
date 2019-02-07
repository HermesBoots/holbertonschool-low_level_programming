#include <stdio.h>

/**
 * main - Entry points, prints numbers without a char variable
 *
 * Return: 0
 */
int main(void)
{
	int c;

	for (c = 48; c < 58; c++)
		putchar(c);
	putchar(10);
	return (0);
}
