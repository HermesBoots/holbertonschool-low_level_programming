#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_postorder - operate on a tree in post-order
 * @tree: tree to process
 * @func: function to call on each node
 */
void binary_tree_postorder(binary_tree_t const *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (tree->left != NULL)
		binary_tree_postorder(tree->left, func);
	if (tree->right != NULL)
		binary_tree_postorder(tree->right, func);
	func(tree->n);
}
