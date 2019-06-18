#include <stdint.h>
#include "sort.h"

#define getParent(i) (((i) - 1) / 2)
#define getLeft(i) (2 * (i) + 1)
#define getRight(i) (2 * (i) + 2)

void fix_heap(int *array, size_t size, size_t root, size_t last)
{
	size_t largest, left, right;

	do {
		left = getLeft(root);
		right = getRight(root);
		largest = root;
		if (right <= last && array[right] > array[root])
			largest = right;
		if (array[left] > array[largest])
			largest = left;
		if (root == largest)
			return;
		array[root] ^= array[largest];
		array[largest] ^= array[root];
		array[root] ^= array[largest];
		if (array[root] != array[largest])
			print_array(array, size);
		root = largest;
	} while (getLeft(root) <= last);
}

/**
 * heap_sort -
 *
 * Return: 
 */
void heap_sort(int *array, size_t size)
{
	size_t node, sorted;

	for (node = getParent(size - 1); node != SIZE_MAX; node--)
		fix_heap(array, size, node, size - 1);
	for (sorted = size - 1; sorted > 1; sorted--)
	{
		array[0] ^= array[sorted];
		array[sorted] ^= array[0];
		array[0] ^= array[sorted];
		if (array[0] != array[sorted])
			print_array(array, size);
		fix_heap(array, size, 0, sorted - 1);
	}
	array[0] ^= array[1];
	array[1] ^= array[0];
	array[0] ^= array[1];
	if (array[0] != array[1])
		print_array(array, size);
}
