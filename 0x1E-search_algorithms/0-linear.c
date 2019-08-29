#include <stdio.h>
#include "search_algos.h"


/**
 * linear_search - do a linear search on an array
 * @array: pointer to first element in array
 * @size: number of items in array
 * @value: value to search for
 * Return: index of value in array or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t index;

	for (index = 0; index < size; index++)
	{
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
		if (array[index] == value)
			return (index);
	}
	return (-1);
}
