#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * error - print an error message and return an error code
 *
 * Return: 1
 */
int error(void)
{
	printf("Error\n");
	return (1);
}

/**
 * main - Entry point, calculates needed coins to make change
 * @argc: number of command-line arguments
 * @argv: list of command-line arguments
 *
 * Return: 0 if argument is valid, 1 otherwise
 */
int main(int argc, char *argv[])
{
	int coins[] = {25, 10, 5, 2, 1};
	int amount, count = 0, index = 0, sofar = 0;

	if (argc != 2)
		return (error());
	amount = atoi(argv[1]);
	if (amount <= 0)
	{
		printf("0\n");
		return (0);
	}

	while (sofar < amount)
	{
		if (INT_MAX - sofar >= coins[index] && sofar + coins[index] <= amount)
		{
			count++;
			sofar += coins[index];
		}
		else
		{
			index++;
		}
	}
	printf("%d\n", count);
	return (0);
}
