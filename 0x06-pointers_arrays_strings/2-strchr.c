#define NULL ((void *)0)

/**
 * _strchr - get first occurrence of a certain character in a string
 * @str: string to search in
 * @c: character to search for
 *
 * Return: pointer to first occurrence if found, NULL otherwise
 */
char *_strchr(char *str, char c)
{
	for (; *str; str++)
	{
		if (*str == c)
			return (str);
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
