#include <errno.h>
#include <stdio.h>

/**
 * main - Entry point, multiplies two command-line arguments
 * @argc: number of command-line arguments
 * @argv: list of command-line arguments
 *
 * Return: 0 if multiplication is possible, 0 if it isn't
 */
int main(int argc, char *argv[])
{
	int a, b, c, d __attribute__ ((unused));

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	c = sscanf(argv[1], "%d%n", &a, &d);
	if (c < 1)
	{
		printf("Error\n");
		return (1);
	}
	c = sscanf(argv[2], "%d%n", &b, &d);
	if (c < 1)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", a * b);
	return (0);
}
