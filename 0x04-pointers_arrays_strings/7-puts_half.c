#include "holberton.h"

/**
 * puts_half - print the second half of a string
 * @s: the string
 */
void puts_half(char *s)
{
	char *sub;
	int len = 0;

	for (sub = s; *sub; sub++)
		len++;
	for (sub -= len / 2; *sub; sub++)
		_putchar(*sub);
	_putchar('\n');
}
