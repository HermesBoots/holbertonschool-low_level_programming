#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_balance - compare the number of nodes in subtrees
 * @tree: tree to compare
 * Return: number of nodes in left subtree - number in right subtree
 */
int binary_tree_balance(binary_tree_t const *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) - binary_tree_size(tree->right));
}

/**
 * binary_tree_size - count the nodes in a binary tree
 * @tree: tree to process
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


/**
 * binary_tree_is_complete - check if binary tree is "complete"
 * @tree: tree to process
 * Return: 0 if not all subtrees are weighted to the left, 1 if they are
 */
int binary_tree_is_complete(binary_tree_t const *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent == NULL && binary_tree_balance(tree) < 0)
		return (0);
	if (tree->left != NULL)
	{
		if (binary_tree_balance(tree->left) < 0)
			return (0);
		if (binary_tree_is_complete(tree->left) == 0)
			return (0);
	}
	if (tree->right != NULL)
	{
		if (binary_tree_balance(tree->right) != 0)
			return (0);
		if (binary_tree_is_complete(tree->right) == 0)
			return (0);
	}
	return (1);
}
