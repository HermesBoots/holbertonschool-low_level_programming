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

	if (size < 1 || array == NULL || action == NULL)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}
