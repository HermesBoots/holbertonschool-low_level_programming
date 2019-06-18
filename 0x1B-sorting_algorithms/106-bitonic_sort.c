#include "sort.h"

#define swap(a, b) do { \
	a ^= b; \
	b ^= a; \
	a ^= b; \
} while (0)

/**
 * do_bitonic_sort - recursive helper function for bitonic_sort
 * @array: array to sort
 * @size: total size of array
 * @start: start index of partition
 * @sublen: size of partition to sort
 * @increasing: whether to sort in increasing or decreasing order
 */
void do_bitonic_sort(int *array, st size, st start, st sublen, char increasing)
{
	size_t i, step;

	printf("Merging [%lu/%lu] (%s):\n", sublen, size, increasing ? "UP" : "DOWN");
	print_array(array + start, sublen);
	if (sublen > 2)
	{
		do_bitonic_sort(array, size, start, sublen / 2, 1);
		do_bitonic_sort(array, size, start + sublen / 2, sublen / 2, 0);
	}
	for (step = sublen / 2; step > 0; step /= 2)
	{
		for (i = start; i + step - start < sublen; i++)
		{
			if (increasing && array[i] > array[i + step])
				swap(array[i], array[i + step]);
			if (!increasing && array[i] < array[i + step])
				swap(array[i], array[i + step]);
		}
	}
	printf("Result [%lu/%lu] (%s):\n", sublen, size, increasing ? "UP" : "DOWN");
	print_array(array + start, sublen);
}

/**
 * bitonic_sort - sort array using bitonic merge algorithm
 * @array: array of ints to sort
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	do_bitonic_sort(array, size, 0, size, 1);
}
