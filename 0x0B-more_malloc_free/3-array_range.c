#include <stdlib.h>

/**
 * array_range - allocate a new array containing a range of integers
 * @min: first value to include
 * @max: last value to include
 *
 * Return: pointer to new array, NULL if args invalid or allocation fails
 */
int *array_range(int min, int max)
{
	int *ret, *sub;
	int i;

	if (min > max)
		return (NULL);
	sub = ret = malloc(sizeof(*ret) * (max - min + 1));
	if (ret == NULL)
		return (NULL);
	for (i = min; i <= max; i++)
		*sub++ = i;
	return (ret);
}
