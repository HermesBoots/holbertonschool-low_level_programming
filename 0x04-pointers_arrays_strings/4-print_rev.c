#include "holberton.h"

/**
 * print_rev - print a string in reverse then add a line feed
 * @s: the string
 */
void print_rev(char *s)
{
	char *sub;

	for (sub = s; *sub; sub++)
		;
	for (sub--; sub >= s; sub--)
		_putchar(*sub);
	_putchar('\n');
}
