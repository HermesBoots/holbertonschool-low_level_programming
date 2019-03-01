#include <ctype.h>
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
 * main - Entry point, adds two command-line arguments
 * @argc: number of command-line arguments
 * @argv: list of command-line arguments
 *
 * Return: 0 if addition is possible, 0 if it isn't
 */
int main(int argc, char *argv[])
{
	char *sub;
	int count = 0, i, sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (sub = argv[i]; *sub; sub++)
		{
			if (!isdigit(*sub))
				return (error());
		}
		count++;
	}

	for (i = 1; i <= count; i++)
		sum += atoi(argv[i]);
	printf("%d\n", sum);
	return (0);
}
