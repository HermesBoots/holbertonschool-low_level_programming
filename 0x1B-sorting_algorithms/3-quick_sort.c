#include "sort.h"
#include <stdio.h>

/**
 * do_quick_sort - recursive helper function for quick_sort
 * @array: array to sort a part of
 * @size: total size of array
 * @start: index to start at
 * @stop: index to stop at
 */
void do_quick_sort(int *array, size_t size, size_t start, size_t stop)
{
	int pivot, swap;
	size_t new_pivot_idx, i;

	pivot = array[stop];
	for (new_pivot_idx = i = start; i < stop; i++)
	{
		if (array[i] < pivot)
		{
			if (new_pivot_idx != i)
			{
				swap = array[new_pivot_idx];
				array[new_pivot_idx] = array[i];
				array[i] = swap;
				print_array(array, size);
			}
			new_pivot_idx++;
		}
	}
	if (new_pivot_idx != stop && pivot != array[new_pivot_idx])
	{
		swap = array[new_pivot_idx];
		array[new_pivot_idx] = array[stop];
		array[stop] = swap;
		print_array(array, size);
	}
	if (new_pivot_idx > start + 1)
		do_quick_sort(array, size, start, new_pivot_idx - 1);
	if (new_pivot_idx < stop - 1)
		do_quick_sort(array, size, new_pivot_idx + 1, stop);
}

/**
 * quick_sort - sort using the Lomuto partition scheme of quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	do_quick_sort(array, size, 0, size - 1);
}
