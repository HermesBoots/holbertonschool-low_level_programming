#include "binary_trees.h"

#define NULL ((void *)0)


void binary_tree_preorder(binary_tree_t const *tree, void (*func)(int))
{
	func(tree->n);
	if (tree->left != NULL)
		binary_tree_preorder(tree->left, func);
	if (tree->right != NULL)
		binary_tree_preorder(tree->right, func);
}
