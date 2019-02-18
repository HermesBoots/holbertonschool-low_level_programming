#include "holberton.h"

/**
 * _puts - prints a string then a line feed
 * @s: the string to print
 */
void _puts(char *s)
{
	char *sub;

	for (sub = s; *sub; sub++)
		_putchar(*sub);
	_putchar('\n');
}
