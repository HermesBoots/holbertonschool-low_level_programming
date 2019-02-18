#include <stdio.h>
/**
 * rev_string - reverse a string in place
 * @s: the string
 */
void rev_string(char *s)
{
	char *left, *right;

	for (right = s; *right; right++)
		;
	for (left = s, right--; left < right; left++, right--)
	{
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}
