#include <stdlib.h>

/**
 * array_iterator - apply a function to each item in an array
 * @array: pointer to array
 * @size: number of items in array
 * @action: function to apply to each item
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
		action(array[i]);
}
