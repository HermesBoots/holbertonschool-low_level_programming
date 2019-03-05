#include <stdlib.h>

/**
 * _strdup - duplicates a string into newly-allocated memory
 * @str: string to copy
 *
 * Return: pointer to copy if success, NULL if str is NULL or allocation fails
 */
char *_strdup(char *str)
{
	char *ret;
	int len = 1;

	if (str == NULL)
		return (NULL);
	for (ret = str; *ret != '\0'; ret++)
		len++;
	ret = malloc(len);
	if (ret != NULL)
	{
		while (len--)
			ret[len] = str[len];
	}
	return (ret);
}
