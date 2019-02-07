#include <stdio.h>

/**
 * main - Entry point, prints digits separated by commas and spaces
 *
 * Return: 0
 */
int main(void)
{
	int digit;

	for (digit = 48; digit < 58; digit++)
	{
		putchar(digit);
		if (digit < 57)
		{
			putchar(44);
			putchar(32);
		}
	}
	putchar(10);
	return (0);
}
