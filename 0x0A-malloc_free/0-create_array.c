#include <stdlib.h>

/**
 * create_array - allocate array of given size and initialize with given value
 * @size: size to allocate
 * @c: value with which to initialize
 *
 * Return: pointer to new array, NULL allocation fails or if size == 0
 */
char *create_array(unsigned int size, char c)
{
	char *ret;
	unsigned int i;

	if (size < 1)
		return (NULL);
	ret = malloc(size);
	if (ret)
	{
		for (i = 0; i < size; i++)
			ret[i] = c;
	}
	return (ret);
}
