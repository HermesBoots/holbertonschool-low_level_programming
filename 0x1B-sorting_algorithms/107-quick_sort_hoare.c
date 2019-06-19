#include "sort.h"
#include <stdio.h>

/**
 * do_quick_sort2 - recursive helper function for quick_sort_hoare
 * @array: array to sort
 * @size: size of array
 * @start: start index of partition
 * @stop: stop index of partition
 */
void do_quick_sort2(int *array, size_t size, size_t start, size_t stop)
{
	int pivot;
	size_t left, right;

	if (start >= stop)
		return;
	pivot = array[stop];
	for (left = start, right = stop; left < right;)
	{
		if (array[left] >= pivot && array[right] <= pivot)
		{
			array[left] ^= array[right];
			array[right] ^= array[left];
			array[left] ^= array[right];
			if (array[left] != array[right])
				print_array(array, size);
			left++;
		}
		if (array[left] < pivot)
			left++;
		else if (array[right] > pivot)
			right--;
	}
	do_quick_sort2(array, size, start, left - 1);
	do_quick_sort2(array, size, left, stop);
}

/**
 * quick_sort_hoare - use the hoare partition scheme with quick sort
 * @array: array to sort
 * @size: size of arrray
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	do_quick_sort2(array, size, 0, size - 1);
}
