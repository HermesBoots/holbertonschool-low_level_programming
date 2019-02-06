#include <stdio.h>
#include <string.h>

/**
  * main - Entry point
  *
  * Return: always 1
  */
int main(void)
{
	char text[59] = "and that piece of art is useful\"";

	memcpy(&text[31], " - Dora Korpar, 2015-10-19\n", 27);

	fwrite(text, 1, sizeof(text) - sizeof(char), stderr);
	return (1);
}
