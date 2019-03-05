#include <stdlib.h>

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
		if (in && *sub == ' ')
		{
			in = 0;
		}
		else if (!in && *sub != ' ')
		{
			in = 1;
			ret++;
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
int _strlen(char *str)
{
	int ret;

	for (ret = 0; str[ret] != '\0'; ret++)
		;
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

	for (ret = 0; str[ret] != '\0' && str[ret] != ' '; ret++)
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

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	if (len == 0)
		return (NULL);
	len = count_words(str);
	ret = malloc((len + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	for (sub = str; *sub == ' '; sub++)
		;
	for (i = 0; i < len; i++)
	{
		ret[i] = tail = malloc(word_len(sub));
		if (tail == NULL)
		{
			for (len = 0; len < i; len++)
				free(ret[len]);
			free(ret);
			return (NULL);
		}
		for (; *sub != ' '; sub++)
			*tail++ = *sub;
		*tail = '\0';
		for (; *sub == ' '; sub++)
			;
	}
	ret[len] = NULL;
	return (ret);
}
