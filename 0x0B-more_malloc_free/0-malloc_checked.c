#include <stdlib.h>

/**
 * malloc_checked - wrap malloc to check for errors
 * @b: number of bytes to allocate
 */
void *malloc_checked(unsigned int b)
{
	void *ret;

	ret = malloc(b);
	if (ret == NULL)
		exit(98);
	return (ret);
}
