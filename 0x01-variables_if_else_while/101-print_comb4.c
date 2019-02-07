#include <stdio.h>

/**
 * main - Entry point, prints combinations of 3 digits without repetition
 *
 * Return: 0
 */
int main(void)
{
	int first, second, third;

	for (first = 48; first < 58; first++)
	{
		for (second = 48; second < 58; second++)
		{
			for (third = 48; third < 58; third++)
			{
				if (third > second && second > first)
				{
					putchar(first);
					putchar(second);
					putchar(third);
					if (first < 55 || second < 56 || third < 57)
					{
						putchar(44);
						putchar(32);
					}
				}
			}
		}
	}
	putchar(10);
	return (0);
}
