#include "holberton.h"

/**
 * print_sign - prints and returns the sign of a number
 * @n: the number to check
 *
 * Description: prints '+', '0', or '-' if number is positive, zero, or
 * negative respectively
 *
 * Return: 1, 0, -1 if number is positive, zero, or negative respectively
 */
int print_sign(int n)
{
	switch ((n > 0) - (n < 0))
	{
	case -1:
		_putchar('-');
		return (-1);
	case 1:
		_putchar('+');
		return (1);
	default:
		_putchar('0');
		return (0);
	}
}
