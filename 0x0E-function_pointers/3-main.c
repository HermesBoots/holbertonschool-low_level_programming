#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point, calculates arithmetic operations
 * @argc: number of command-line arguments
 * @argv: list of command-line arguments
 *
 * Return: 0 if success, 98-100 if errors occur
 */
int main(int argc, char *argv[])
{
	int (*op)(int, int);

	if (argc != 4)
	{
		puts("Error");
		return (98);
	}
	op = get_op_func(argv[2]);
	if (op == NULL)
	{
		puts("Error");
		return (99);
	}
	printf("%d\n", op(atoi(argv[1]), atoi(argv[3])));
	return (0);
}
