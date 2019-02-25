#define NULL ((void *)0)

/**
 * _strpbrk - get pointer to first appearance of one of a set of characters
 * @str: string to search through
 * @accept: string containing list of characters to look for
 *
 * Return: pointer to first appearance of character in accept, NULL if none
 */
char *_strpbrk(char *str, char *accept)
{
	char *sub;

	for (; *str; str++)
	{
		for (sub = accept; *sub; sub++)
		{
			if (*str == *sub)
				return (str);
		}
	}
	return (NULL);
}
