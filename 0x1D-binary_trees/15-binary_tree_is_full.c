#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_is_full - check if all nodes in a tree have 0 or 2 children
 * @tree: tree to process
 * Return: 0 if tree is NULL or is not full, 1 otherwise
 */
int binary_tree_is_full(binary_tree_t const *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right != NULL)
		return (0);
	if (tree->left != NULL && tree->right == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (binary_tree_is_full(tree->left) == 0)
		return (0);
	if (binary_tree_is_full(tree->right) == 0)
		return (0);
	return (1);
}
