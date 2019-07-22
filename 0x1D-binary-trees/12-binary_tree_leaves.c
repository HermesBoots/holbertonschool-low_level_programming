#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_leaves - count the childless nodes in a binary tree
 * @tree: tree to process
 * Return: number of leaves in the tree
 */
size_t binary_tree_leaves(binary_tree_t const *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left = binary_tree_leaves(tree->left);
	if (tree->right != NULL)
		right = binary_tree_leaves(tree->right);
	if (left == 0 && right == 0)
		return (1);
	return (left + right);
}
