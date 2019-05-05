#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * main - entry point, generates passwords for crackme5
 * @argc: number of command-line arguments
 * @argv: vector of command-line arguments
 *
 * Return: 1 if arguments invalid, 0 otherwise
 */
int main(int argc, char *argv[])
{
	char pass[64] =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	size_t name_len;
	unsigned int i, result = 0;

	if (argc != 2)
		return (1);
	name_len = strlen(argv[1]);
	putchar(pass[(name_len ^ 0x3b) & 0x3f]);
	for (i = 0; i < name_len; i++)
		result += argv[1][i];
	putchar(pass[(result ^ 0x4f) & 0x3f]);
	for (i = 0, result = 1; i < name_len; i++)
		result *= argv[1][i];
	putchar(pass[(result ^ 0x55) & 0x3f]);
	for (i = 0, result = 0; i < name_len; i++)
	{
		if ((unsigned char)argv[1][i] > result)
			result = argv[1][i];
	}
	srand(result ^ 0xe);
	putchar(pass[rand() & 0x3f]);
	for (i = 0, result = 0; i < name_len; i++)
		result += argv[1][i] * argv[1][i];
	putchar(pass[(result ^ 0xef) & 0x3f]);
	for (i = 0, result = 0; i < (unsigned char)argv[1][0]; i++)
		result = rand();
	putchar(pass[(result ^ 0xe5) & 0x3f]);
	return (0);
}
