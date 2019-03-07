#include <stdlib.h>

/**
 * _realloc - allocate more memory for existing array
 * @ptr: pointer to previous allocation
 * @old_size: size of previous allocation
 * @new_size: size needed for new allocation
 *
 * Return: pointer to new memory or NULL if args invalid or allocation fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ret;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	ret = malloc(new_size);
	if (ret == NULL)
		return (NULL);
	for (i = 0; i < (old_size < new_size ? old_size : new_size); i++)
		ret[i] = ((char *)ptr)[i];
	free(ptr);
	return (ret);
}
