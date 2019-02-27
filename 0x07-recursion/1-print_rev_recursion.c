#include "holberton.h"

/**
 * _print_rev_recursion - print a string backward
 * @str: string to print
 */
void _print_rev_recursion(char *str)
{
	if (*str)
	{
		_print_rev_recursion(str + 1);
		_putchar(*str);
	}
}
