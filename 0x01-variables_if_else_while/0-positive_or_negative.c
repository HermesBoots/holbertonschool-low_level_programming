#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * sign - Get sign of integer
 * @arg: integer to check
 *
 * Return: 1 if positive, -1 if negative, 0 if zero
 */
inline int sign(int arg)
{
	return ((arg > 0) - (arg < 0));
}

/**
 * main - Entry point, generates a random number and prints its sign
 *
 * Return: 0
 */
int main(void)
{
	int n;
	char const * const messages[] = {
		"is negative",
		"is zero",
		"is positive"
	};

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	printf("%d %s\n", n, messages[1 + sign(n)]);
	return (0);
}
