#include <stdio.h>

/**
 * main - Entry point, prints first argument
 * @argc: command-line argument count
 * @argv: array of command-line arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[] __attribute__ ((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
