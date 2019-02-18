#include "holberton.h"

/**
 * puts2 - print every other character in a string, starting at the first
 * @s: the string
 */
void puts2(char *s)
{
	char *sub;
	char printing = 1;

	for (sub = s; *sub; sub++)
	{
		if (printing)
			_putchar(*sub);
		printing = !printing;
	}
	_putchar('\n');
}
