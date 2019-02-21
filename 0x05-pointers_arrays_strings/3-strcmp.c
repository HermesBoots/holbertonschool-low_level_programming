#include <stdio.h>

/**
 * _strcmp - compare two strings
 * @s1: one of the strings
 * @s2: the other string
 *
 * Return: 0 if strings match, negative if s1 is lower, positive if s2 is lower
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i] && s2[i]; i++)
		;
	if (s1[i] < s2[i])
		return (-i - 1);
	else if (s2[i] < s1[i])
		return (i + 1);
	return (0);
}
