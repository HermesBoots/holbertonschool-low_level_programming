#include <stdio.h>

/**
 * main - Entry point, prints all combinations of two digits without repetition
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
			if (second > first)
			{
				putchar(first);
				putchar(second);
				if (first < 56 || second < 57)
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
