#include <stddef.h>
#include "binary_trees.h"


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
