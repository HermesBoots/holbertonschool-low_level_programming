#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_preorder - operate on a tree in pre-order
 * @tree: tree to process
 * @func: function to call on each node
 */
void binary_tree_preorder(binary_tree_t const *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	if (tree->left != NULL)
		binary_tree_preorder(tree->left, func);
	if (tree->right != NULL)
		binary_tree_preorder(tree->right, func);
}
