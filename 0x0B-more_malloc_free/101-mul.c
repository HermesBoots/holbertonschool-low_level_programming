#include <stdlib.h>
#include "holberton.h"

#define _UINT_MAX 4294967295u

/**
 * error - Print error message and return error code
 */
void error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * isnumeric - check if string is entirely numeric
 * @str: string to check
 *
 * Return: string length if string is numeric, 0 if it isn't
 */
unsigned int isnumeric(char *str)
{
	unsigned int ret = 0;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		ret++;
		str++;
	}
	return (ret);
}

/**
 * print_int - prints an integer from a string, one character at a time
 * @str: string storing number to print
 */
void print_int(char *str)
{
	char leading = 1;

	while (*str != '\0')
	{
		if (!leading || *str != '0')
			_putchar(*str);
		if (*str != '0')
			leading = 0;
		str++;
	}
	if (leading)
		_putchar('0');
}

/**
 * bigadd - add two arbitrary-precision numbers
 * @op1: first operand, stores result
 * @op2: second operand
 * @power: order of magnitude of op2
 * @len: length of operands
 */
void bigadd(char *op1, unsigned int op2, unsigned int power, unsigned int len)
{
	char carry = 0;
	unsigned int index, isum;

	index = len - power - 1;
	isum = op1[index] - '0' + op2 % 10;
	if (isum >= 10)
		carry = 1;
	op1[index] = isum % 10 + '0';
	index--;
	isum = op1[index] - '0' + op2 / 10 + carry;
	if (isum >= 10)
		carry = 1;
	else
		carry = 0;
	op1[index] = isum % 10 + '0';
	index--;
	while (carry)
	{
		isum = op1[index] - '0' + carry;
		if (isum < 10)
			carry = 0;
		op1[index] = isum % 10 + '0';
		index--;
	}
}

/**
 * bigmul - multiply two arbitrary-precision numbers
 * @op1: first operand
 * @len1: length of first operand
 * @op2: second operand
 * @len2: length of second operand
 * @sum: string that stores sum of products, final answer
 * @lens: length of sum string
 */
void bigmul(
		char *op1, unsigned int len1,
		char *op2, unsigned int len2,
		char *sum, unsigned int lens
)
{
	unsigned int digit1, digit2, power, product;

	for (digit1 = len1 - 1; digit1 != _UINT_MAX; digit1--)
	{
		for (digit2 = len2 - 1; digit2 != _UINT_MAX; digit2--)
		{
			product = (op1[digit1] - '0') * (op2[digit2] - '0');
			power = (len1 - digit1) + (len2 - digit2) - 2;
			bigadd(sum, product, power, lens);
		}
	}
	print_int(sum);
	_putchar('\n');
}

/**
 * main - Entry point
 * @argc: number of command-line arguments
 * @argv: list of command-line arguments
 *
 * Return: 98 if argc != 2 or if an arg isn't numeric, 0 otherwise
 */
int main(int argc, char *argv[])
{
	char *sum;
	unsigned int i, len1, len2, lens;

	if (argc != 3)
		error();
	len1 = isnumeric(argv[1]);
	if (len1 == 0)
		error();
	len2 = isnumeric(argv[2]);
	if (len2 == 0)
		error();
	lens = len1 + len2;
	sum = malloc(lens + 1);
	if (sum == NULL)
		error();
	sum[lens] = '\0';
	for (i = 0; i < lens; i++)
		sum[i] = '0';
	bigmul(
			argv[1], len1,
			argv[2], len2,
			sum, lens
	);
	free(sum);
	return (0);
}
