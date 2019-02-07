#include <stdio.h>

/**
 * main - Entry point, prints numbers from 0 to 99
 *
 * Return: 0
 */
int main(void)
{
	int first, second;

	for (first = 48; first < 58; first++)
	{
		for (second = 48; second < 58; second++)
		{
			putchar(first);
			putchar(second);
			if (first < 57 || second < 57)
			{
				putchar(44);
				putchar(32);
			}
		}
	}
	putchar(10);
	return (0);
}
