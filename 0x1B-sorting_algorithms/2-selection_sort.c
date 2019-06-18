#include "sort.h"

/**
 * selection_sort - sort array of ints using selection sort
 * @array: pointer to array of ints
 * @size: size of array
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[smallest])
				smallest = j;
		if (smallest != i)
		{
			array[smallest] ^= array[i];
			array[i] ^= array[smallest];
			array[smallest] ^= array[i];
			print_array(array, size);
		}
	}
}
