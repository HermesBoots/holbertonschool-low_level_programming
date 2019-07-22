#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_size - count the nodes in a binary tree
 * @tree: tree to process
 * @size: number of nodes so far
 * Return: number of nodes in tree
 */
size_t binary_tree_size(binary_tree_t const *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left = binary_tree_size(tree->left);
	if (tree->right != NULL)
		right = binary_tree_size(tree->right);
	if (left == 0 && right == 0)
		return (1);
	return (1 + left + right);
}
