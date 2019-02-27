#include "holberton.h"

/**
 * _puts_recursion - print a string using recursion
 * @str: string to print
 */
void _puts_recursion(char *str)
{
	if (*str)
	{
		_putchar(*str++);
		_puts_recursion(str);
	}
	else
	{
		_putchar('\n');
	}
}
