#include "holberton.h"

/**
 * _isalpha - checks whether a character is a letter
 * @c: the character to check
 *
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
