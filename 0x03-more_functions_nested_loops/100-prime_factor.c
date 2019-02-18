#include <math.h>
#include <stdio.h>

/**
 * main - Entry point, finds largest prime factor of 612852475143
 *
 * Return: 0
 */
int main(void)
{
	long double root;
	long final = 612852475143;
	long factor, largest = 0, prime;

	for (factor = 2; factor <= final; factor += 1)
	{
		if (final % factor == 0)
		{
			if (factor % 2 != 0 || factor <= 2)
			{
				root = sqrt(factor);
				for (prime = 3; prime < root; prime += 2)
				{
					if (factor % prime == 0)
						break;
				}
				if (prime >= root)
				{
					largest = factor;
					final = final / factor;
				}
			}
		}
	}

	printf("%li\n", largest);
	return (0);
}
