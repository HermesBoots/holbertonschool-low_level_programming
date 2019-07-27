#include "binary_trees.h"


/**
 * array_to_avl - create a new AVL tree using values from an array
 * @array: array to use values from
 * @size: size of the array
 * Return: root of new tree or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i;

	if (size == 0)
		return (NULL);
	tree = avl_insert(&tree, *array);
	for (i = 1; i < size; i++)
		avl_insert(&tree, array[i]);
	return (tree);
}
