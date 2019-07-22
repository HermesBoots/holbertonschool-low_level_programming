#include <stddef.h>
#include "binary_trees.h"


/**
 * binary_tree_nodes - count the number of nodes with children in a tree
 * @tree: tree to process
 * Return: number of nodes with children
 */
size_t binary_tree_nodes(binary_tree_t const *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left = binary_tree_nodes(tree->left);
	if (tree->right != NULL)
		right = binary_tree_nodes(tree->right);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (left + right + 1);
}
