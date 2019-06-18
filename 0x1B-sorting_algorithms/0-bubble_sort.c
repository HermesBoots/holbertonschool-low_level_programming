#include "sort.h"

/**
 * bubble_sort - sort an array of ints using bubble sort algorithm
 * @array: pointer to array of ints
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, num_swaps;

	if (array == NULL)
		return;
	do {
		num_swaps = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] ^= array[j + 1];
				array[j + 1] ^= array[j];
				array[j] ^= array[j + 1];
				num_swaps++;
				print_array(array, size);
			}
		}
	} while (num_swaps != 0);
}
