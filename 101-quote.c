#include <stdio.h>
#include <string.h>

/**
  * main - Entry point, prints a string without `printf` or `puts`
  *
  * Return: always 1
  */
int main(void)
{
	char output[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	fwrite(output, sizeof(char), sizeof(output) - 1, stderr);
	return (1);
}
