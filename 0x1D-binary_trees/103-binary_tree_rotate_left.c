#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_rotate_left - rotate a tree to the left once
 * @tree: tree to rotate
 * Return: new root node of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL)
		return (NULL);
	root = tree->right;
	if (root != NULL)
	{
		tree->right = root->left;
		if (root->left != NULL)
			root->left->parent = tree;
		root->left = tree;
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
