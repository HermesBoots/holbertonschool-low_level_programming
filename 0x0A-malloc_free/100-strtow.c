#include <stdlib.h>

/**
 * _isspace - check if character is white space
 * @c: character to check
 *
 * Return: 1 if character is white space, 0 if it isn't
 */
int _isspace(int c)
{
	return (c == ' ');
}

/**
 * count_words - count the number of words in a string
 * @str: string to examine, must be a string
 *
 * Return: number of words in string
 */
int count_words(char *str)
{
	char const *sub;
	int in = 0, ret = 0;

	for (sub = str; *sub != '\0'; sub++)
	{
		if (in && _isspace(*sub))
		{
			in = 0;
		}
		else if (!in && !_isspace(*sub))
		{
			in = 1;
			ret++;
		}
	}
	return (ret);
}

/**
 * word_len - get the length of a word
 * @str: pointer to beginning of word
 *
 * Return: length of word
 */
int word_len(char *str)
{
	int ret;

	for (ret = 0; str[ret] != '\0' && !_isspace(str[ret]); ret++)
		;
	return (ret);
}

/**
 * _strlen - get length of a string
 * @str: string to examine, must be a string and not NULL
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int ret;

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
	int i, len;

	if (str == NULL || *str == '\0')
		return (NULL);
	len = _strlen(str);
	tail = malloc(len + 1);
	if (tail == NULL)
		return (NULL);
	len = count_words(str);
	if (len < 1)
	{
		free(tail);
		return (NULL);
	}
	ret = malloc((len + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	for (sub = str; _isspace(*sub); sub++)
		;
	for (i = 0; i < len; i++)
	{
		ret[i] = tail;
		for (; !_isspace(*sub) && *sub != '\0'; sub++)
			*tail++ = *sub;
		*tail++ = '\0';
		for (; _isspace(*sub); sub++)
			;
	}
	ret[len] = NULL;
	return (ret);
}
