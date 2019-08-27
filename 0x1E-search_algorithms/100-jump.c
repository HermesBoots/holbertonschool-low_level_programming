#include <math.h>
#include <stdio.h>
#include "search_algos.h"


/**
 * jump_search - search a sorted array using jump search
 * @array: pointer to first element in array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index of value in array or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t gap, index;

	if (size == 0 || (size == 1 && array[0] != value))
		return (-1);
	gap = sqrt(size);
	for (index = 0; index < size; index += gap)
	{
		if (array[index] >= value)
			break;
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
	}
	if (index == 0)
		return (-1);
	index -= gap;
	gap = index + gap;
	printf("Value found between indexes [%lu] and [%lu]\n", index, gap);
	while (index < size && index <= gap)
	{
		if (array[index] == value)
		{
			printf("Value checked array[%lu] = [%d]\n", index, array[index]);
			return (index);
		}
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
		index++;
	}
	return (-1);
}
