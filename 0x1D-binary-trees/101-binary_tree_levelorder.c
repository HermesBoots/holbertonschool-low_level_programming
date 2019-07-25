#include <stddef.h>
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
		return 0;
	return (do_tree_height(tree, 0));
}


/**
 * do_tree_levelorder - recursive helper function for binary_tree_levelorder
 * @tree: tree to process
 * @func: function to call on each node
 * @depth: level of nodes to operate on
 */
void do_tree_levelorder(
	binary_tree_t const *tree,
	void (*func)(int),
	size_t depth
)
{
	if (depth == 0)
	{
		func(tree->n);
		return;
	}
	if (tree->left != NULL)
		do_tree_levelorder(tree->left, func, depth - 1);
	if (tree->right != NULL)
		do_tree_levelorder(tree->right, func, depth - 1);
}


/**
 * binary_tree_levelorder - operate on a tree in level-order
 * @tree: tree to process
 * @func: function to call on each node in the tree
 */
void binary_tree_levelorder(binary_tree_t const *tree, void (*func)(int))
{
	size_t height, i;

	height = binary_tree_height(tree);
	for (i = 0; i < height; i++)
		do_tree_levelorder(tree, func, i);
}
