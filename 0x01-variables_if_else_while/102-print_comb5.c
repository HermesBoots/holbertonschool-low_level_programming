#include <stdio.h>

/**
 * main - Entry point, prints all unique combinations of two two-digit numbers
 *
 * Return: 0
 */
int main(void)
{
	int first, second;

	for (first = 0; first < 100; first++)
	{
		for (second = 0; second < 100; second++)
		{
			if (second > first)
			{
				putchar(48 + first / 10);
				putchar(48 + first % 10);
				putchar(32);
				putchar(48 + second / 10);
				putchar(48 + second % 10);
				if (first < 98 || second < 99)
				{
					putchar(44);
					putchar(32);
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
