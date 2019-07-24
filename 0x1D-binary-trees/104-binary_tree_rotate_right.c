#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_rotate_right - rotate a tree to the right once
 * @tree: tree to rotate
 * Return: new root node of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL)
		return (NULL);
	root = tree->left;
	if (root != NULL)
	{
		tree->left = root->right;
		if (root->right != NULL)
			root->right->parent = tree;
		root->right = tree;
		if (tree->parent != NULL)
		{
			if (tree->parent->left == tree)
				tree->parent->left = root;
			else
				tree->parent->right = root;
		}
		root->parent = tree->parent;
		tree->parent = root;
	}
	return (root);
}
