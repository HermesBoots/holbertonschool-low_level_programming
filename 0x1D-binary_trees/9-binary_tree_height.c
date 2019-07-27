#include <stdio.h>
#include "binary_trees.h"


/**
 * do_tree_height - recursive helper function for binary_tree_height
 * @tree: tree to measure
 * @height: height so far
 * Return: height of this branch of the tree
 */
size_t do_tree_height(binary_tree_t const *tree, size_t height)
{
	size_t left = 0, right = 0;

	height++;
	if (tree->left != NULL)
		left = do_tree_height(tree->left, height);
	if (tree->right != NULL)
		right = do_tree_height(tree->right, height);
	if (left == 0 && right == 0)
		return (height);
	return (left > right ? left : right);
}

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: tree to measure
 * Return: height of the tree
 */
size_t binary_tree_height(binary_tree_t const *tree)
{
	if (tree == NULL)
		return (0);
	return (do_tree_height(tree, 0));
}
