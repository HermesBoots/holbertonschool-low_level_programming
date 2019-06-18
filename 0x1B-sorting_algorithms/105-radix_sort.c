#include <stdint.h>
#include "sort.h"

/**
 * radix_sort - sort with radix sort, heavily favoring speed over memory usage
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	unsigned char digit;
	size_t counts[10];
	size_t index, total;
	int *copy, pow10 = 1;

	if (array == NULL || size < 2)
		return;
	copy = malloc(size * sizeof(int));
	if (copy == NULL)
		return;
	do {
		total = 0;
		for (digit = 0; digit < 10; digit++)
			counts[digit] = 0;
		for (index = 0; index < size; index++)
		{
			digit = array[index] / pow10 % 10;
			counts[digit]++;
			total += digit % 10 == 0 ? 0 : 1;
		}
		if (total == 0)
			continue;
		for (digit = 1; digit < 10; digit++)
			counts[digit] += counts[digit - 1];
		for (index = size - 1; index != SIZE_MAX; index--)
			copy[counts[array[index] / pow10 % 10]-- - 1] = array[index];
		for (index = 0; index < size; index++)
			array[index] = copy[index];
		pow10 *= 10;
		print_array(array, size);
	} while (total != 0 && pow10 <= 1000000000);
	free(copy);
}
