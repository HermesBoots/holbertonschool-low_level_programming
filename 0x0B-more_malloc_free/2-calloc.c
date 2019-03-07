#include <stdlib.h>

/**
 * _calloc - allocate an array and initialize it
 * @nmemb: number of items to allocate space for
 * @size: size of each item to allocate
 *
 * Return: pointer to new memory, NULL if an arg is 0 or allocation fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ret;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ret = malloc(nmemb * size);
	if (ret == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
		ret[i] = 0;
	return (ret);
}
