#include <stdio.h>

/**
  * main - Entry point
  *
  * Return: always 1
  */
int main(void)
{
	char text[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	fwrite(text, 1, sizeof(text) - sizeof(char), stderr);
	return (1);
}
