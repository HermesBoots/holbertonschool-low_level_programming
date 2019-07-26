#include <stddef.h>
#include "binary_trees.h"


/**
 * do_avl_from_sorted - recursive helper function for sorted_array_to_avl
 * @array: array to take values from
 * @size: size of the array
 * @node: node to insert values in
 */
void do_avl_from_sorted(int *array, size_t size, avl_t *node)
{
	avl_t *new;
	size_t middle;

	middle = (size - 1) / 2;
	new = binary_tree_node(node, array[middle]);
	if (new == NULL)
		return;
	if (array[middle] < node->n)
		node->left = new;
	else
		node->right = new;
	if (middle != 0)
		do_avl_from_sorted(array, middle, new);
	if (size - middle > 1)
		do_avl_from_sorted(array + middle + 1, size - middle - 1, new);
}

/**
 * sorted_array_to_avl - fill a new AVL tree with values from a sorted array
 * @array: array to use values from
 * @size: size of the array
 * Return: root of the new tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	if (size == 0)
		return (NULL);
	middle = (size - 1) / 2;
	root = binary_tree_node(NULL, array[middle]);
	if (root == NULL)
		return (NULL);
	if (middle != 0)
		do_avl_from_sorted(array, middle, root);
	if (size - middle > 1)
		do_avl_from_sorted(array + middle + 1, size - middle - 1, root);
	return (root);
}
