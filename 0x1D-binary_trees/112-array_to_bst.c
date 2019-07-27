#include <stddef.h>
#include "binary_trees.h"


/**
 * array_to_bst - fill a new binary search tree with values from an array
 * @array: pointer to array with data to fill
 * @size: number of items to store in tree
 * Return: root node of tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (size == 0)
		return (NULL);
	tree = bst_insert(&tree, *array);
	for (i = 1; i < size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
