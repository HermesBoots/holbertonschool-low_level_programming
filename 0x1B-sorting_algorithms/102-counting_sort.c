#include "sort.h"

/**
 * counting_sort - sort by counting occurrences in an integer list
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *counts;
	size_t counti, arrayi, copyi, largest = 0;

	if (array == NULL || size < 2)
		return;
	for (arrayi = 0; arrayi < size; arrayi++)
	{
		if ((size_t)array[arrayi] > largest)
			largest = array[arrayi];
	}
	largest++;
	counts = malloc(largest * sizeof(int));
	if (counts == NULL)
		return;
	for (counti = 0; counti < largest; counti++)
		counts[counti] = 0;
	for (arrayi = 0; arrayi < size; arrayi++)
		counts[array[arrayi]]++;
	for (counti = 1; counti < largest; counti++)
		counts[counti] += counts[counti - 1];
	print_array(counts, largest);
	for (counti = largest - 1; counti > 0; counti--)
		counts[counti] -= counts[counti - 1];
	for (counti = arrayi = 0; counti < largest; counti++)
	{
		for (copyi = 0; copyi < (size_t)counts[counti]; copyi++, arrayi++)
			array[arrayi] = counti;
	}
	free(counts);
}
