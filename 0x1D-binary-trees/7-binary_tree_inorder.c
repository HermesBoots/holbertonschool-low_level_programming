#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_inorder - process a binary tree in-order
 * @tree: tree to process
 * @func: function to call on each node
 */
void binary_tree_inorder(binary_tree_t const *tree, void (*func)(int))
{
	if (tree->left != NULL)
		binary_tree_inorder(tree->left, func);
	func(tree->n);
	if (tree->right != NULL)
		binary_tree_inorder(tree->right, func);
}
