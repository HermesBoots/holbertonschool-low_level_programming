#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_is_bst - check if tree is sorted like a binary search tree
 * @tree: tree to check
 * Return: 1 if tree exists and is a BST, 0 otherwise
 */
int binary_tree_is_bst(binary_tree_t const *tree)
{
	char side = 'x';

	if (tree == NULL)
		return (0);
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			side = 'l';
		else
			side = 'r';
	}
	if (tree->left != NULL)
	{
		if (tree->left->n >= tree->n)
			return (0);
		if (side == 'l' && tree->left->n >= tree->parent->n)
			return (0);
		if (side == 'r' && tree->left->n <= tree->parent->n)
			return (0);
		if (binary_tree_is_bst(tree->left) == 0)
			return (0);
	}
	if (tree->right != NULL)
	{
		if (tree->right->n <= tree->n)
			return (0);
		if (side == 'l' && tree->right->n >= tree->parent->n)
			return (0);
		if (side == 'r' && tree->right->n <= tree->parent->n)
			return (0);
		if (binary_tree_is_bst(tree->right) == 0)
			return (0);
	}
	return (1);
}
