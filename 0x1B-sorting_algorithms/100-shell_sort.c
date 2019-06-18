#include "sort.h"
#include <stdint.h>
#include <stdio.h>

/**
 * shell_sort - sort an array of ints via shellsort
 * @array: array of ints to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, gap_index, start, sorted, stop, unsorted;

	size_t gaps[] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524,
		88573, 265720, 797161, 2391484, 7174453, 21523360, 64570081,
		193710244, 581130733, 1743392200, 5230176601, 15690529804,
		47071589413, 141214768240, 423644304721, 1270932914164,
		3812798742493, 11438396227480, 34315188682441, 102945566047324,
		308836698141973, 926510094425920, 2779530283277761, 8338590849833284,
		25015772549499852, 75047317648499552, 225141952945498688,
		675425858836496000, 2026277576509488128};

	if (array == NULL || size < 2)
		return;
	for (gap_index = 0; gaps[gap_index] < size / 3; gap_index++)
		;
	while (gap_index != SIZE_MAX)
	{
		gap = gaps[gap_index];
		for (start = 0; start < gap; start++)
		{
			for (stop = start + gap; stop < size; stop += gap)
			{
				unsorted = stop, sorted = stop - gap;
				while (sorted < size && array[sorted] > array[unsorted])
				{
					array[sorted] ^= array[unsorted];
					array[unsorted] ^= array[sorted];
					array[sorted] ^= array[unsorted];
					sorted -= gap, unsorted -= gap;
				}
			}
		}
		gap_index--;
		print_array(array, size);
	}
}
