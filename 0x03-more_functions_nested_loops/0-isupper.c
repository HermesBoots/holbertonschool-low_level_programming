#include "holberton.h"

/**
 * _isupper - determine whether a character is an upper case letter
 * @c: the character to check
 *
 * Return: 1 if c is an upper case letter, 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
