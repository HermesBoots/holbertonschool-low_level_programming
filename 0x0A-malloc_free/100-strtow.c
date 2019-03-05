#include <ctype.h>
#include <stdlib.h>

/**
 * count_words - count the number of words in a string
 * @str: string to examine, must be a string
 *
 * Return: number of words in string
 */
size_t count_words(char const *str)
{
	char const *sub;
	int in = 0;
	size_t ret = 0;

	for (sub = str; *sub != '\0'; sub++)
	{
		if (in && isspace(*sub))
		{
			in = 0;
		}
		else if (!in && !isspace(*sub))
		{
			in = 1;
			ret ++;
		}
	}
	return (ret);
}

/**
 * _strlen - get the length of a string
 * @str: string to examine, must be a string
 *
 * Return: length of str
 */
size_t _strlen(char const *str)
{
	size_t ret;

	for (ret = 0; str[ret] != '\0'; ret++)
		;
	return (ret);
}

/**
 * strtow - split a string into words
 * @str: string to split
 *
 * Return: pointer to NULL-terminated array of words
 */
char **strtow(char *str)
{
	char **ret, *sub, *tail;
	size_t i, len;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	if (len == 0)
		return (NULL);
	tail = malloc(len + 1);
	if (tail == NULL)
		return (NULL);
	len = count_words(str);
	ret = malloc((len + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	for (sub = str; isspace(*sub); sub++)
		;
	for (i = 0; i < len; i++)
	{
		ret[i] = tail;
		for (; !isspace(*sub); sub++)
			*tail++ = *sub;
		*tail++ = '\0';
		for (; isspace(*sub); sub++)
			;
	}
	ret[len] = NULL;
	return (ret);
}
