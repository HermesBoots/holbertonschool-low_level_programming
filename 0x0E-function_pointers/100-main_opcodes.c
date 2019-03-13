#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point, prints own machine code
 * @argc: number of command-line arguments
 * @argv: list of command-line arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int count;
	unsigned char *code;

	if (argc != 2)
	{
		printf("Error\n");
		return (2);
	}
	count = atoi(argv[1]);
	code = (unsigned char *)&main;
	while (count--)
	{
		printf("%02hx", *code++);
		if (count)
			printf(" ");
	}
	printf("\n");
	return (0);
}
