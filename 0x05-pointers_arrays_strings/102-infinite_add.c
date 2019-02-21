#include <stdio.h>

#define NULL ((void *)0)

/**
 * char_sum - adds two characters as digits involving a carry flag
 * @a: first operand of sum
 * @b: second operand of sum
 * @carry: third operand, also set if sum is above 10
 *
 * Return: (sum of a, b, and carry) % 10
 */
int char_sum(char a, char b, char *carry)
{
	int sum;

	sum = a - '0' + b - '0' + *carry;
	if (sum >= 10)
	{
		*carry = 1;
		sum -= 10;
	}
	else
	{
		*carry = 0;
	}
	return (sum + '0');
}

/**
 * move_over - move bytes from one location to another in an overlapping buffer
 * @dest: the location to move to
 * @src: the location to move from
 * @n: number of bytes to move
 */
void move_over(char *dest, char *src, int n)
{
	while (n--)
		*dest++ = *src++;
	dest[-1] = '\0';
}

/**
 * infinite_add - Adds two huge integers stored as strings
 * @n1: an operand
 * @n2: other operand
 * @r: buffer in which to store the result
 * @size_r: size of r
 *
 * Return: NULL if result does not fit in r, r otherwise
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	char carry = 0;
	char *p1, *p2, *pr;

	for (p1 = n1; *p1; p1++)
		;
	for (p2 = n2; *p2; p2++)
		;
	pr = r + size_r - 1;

	for (p1--, p2--; p1 >= n1 && p2 >= n2 && pr > r; pr--, p1--, p2--)
		*pr = char_sum(*p1, *p2, &carry);
	if (p1 < n1)
	{
		p1 = p2;
		n1 = n2;
	}
	for (; p1 >= n1 && pr > r; p1--, pr--)
		*pr = char_sum(*p1, '0', &carry);
	if (carry && pr >= r)
		*pr-- = '1';
	if ((pr <= r && p1 >= n1) || (pr < r))
		return (NULL);
	move_over(r, pr + 1, size_r - (pr - r));
	return (r);
}
