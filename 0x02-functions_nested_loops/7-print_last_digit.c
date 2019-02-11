#include "holberton.h"

/**
 * print_last_digit - print and return last digit of a number
 * @n: the number to get the digit from
 *
 * Return: the last digit of n
 */
int print_last_digit(int n)
{
	int digit;

	digit = _abs(n % 10);
	_putchar(digit + '0');
	return (digit);
}
