#include <stdlib.h>

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
 * argstostr - concatenate many strings into a newly-allocated one
 * @ac: number of strings to concatenate
 * @av: pointer to list of strings to concatenate
 *
 * Return: pointer to new string, NULL if allocation fails or an argument is 0
 */
char *argstostr(int ac, char **av)
{
	char *ret, *sub, *tail;
	int i;
	long total = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
		total += _strlen(av[i]);
	ret = tail = malloc(total + ac + 1);
	if (ret == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (sub = av[i]; *sub != '\0'; sub++)
			*tail++ = *sub;
		*tail++ = '\n';
	}
	*tail = '\0';
	return (ret);
}
