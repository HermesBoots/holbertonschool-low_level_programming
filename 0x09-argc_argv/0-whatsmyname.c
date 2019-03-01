#include <stdio.h>

/**
 * main - Entry point, prints program name
 * @argc: command-line argument count
 * @argv: array of command-line arguments
 *
 * Return: 0
 */
int main(int argc __attribute__ ((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
