#include <stdlib.h>

/**
 * _strlen - get length of string
 * @str: string to examine
 *
 * Return: string length
 */
unsigned int _strlen(char *str)
{
	unsigned int ret = 0;

	while (*str != '\0')
	{
		ret++;
		str++;
	}
	return (ret);
}

/**
 * string_nconcat - concatenate limited bytes to new memory
 * @s1: string to copy in its entirely
 * @s2: string to copy just n bytes of
 * @n: number of bytes from s2 to copy
 *
 * Return: pointer to new string or NULL if allocation failed
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ret, *sub;
	unsigned int len;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len = _strlen(s2);
	len = (len < n ? len : n) + _strlen(s1);
	sub = ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	for (len = 0; s1[len] != '\0'; len++)
		*sub++ = s1[len];
	for (len = 0; s2[len] != '\0' && len < n; len++)
		*sub++ = s2[len];
	*sub = '\0';
	return (ret);
}
