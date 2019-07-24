#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * bst_remove - remove a node from a binary search tree
 * @root: tree to modify
 * @value: value of node to remove
 * Return: root of the tree (may differ from root parameter)
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *next = NULL, *node;

	node = bst_search(root, value);
	if (node == NULL)
		return (root);
	if (node->left != NULL && node->right == NULL)
	{
		for (next = node->left; next->right != NULL; next = next->right)
			;
		if (next != node->left)
		{
			next->parent->right = next->left;
			next->left = node->left;
		}
		next->parent = node->parent;
		next->right = node->right;
	}
	else if (node->right != NULL)
	{
		for (next = node->right; next->left != NULL; next = next->left)
			;
		if (next != node->right)
		{
			next->parent->left = next->right;
			next->right = node->right;
		}
		next->parent = node->parent;
		next->left = node->left;
	}
	if (node->parent != NULL && node->parent->left == node)
		node->parent->left = next;
	if (node->parent != NULL && node->parent->right == node)
		node->parent->right = next;
	free(node);
	if (next != NULL && next->left != NULL)
		next->left->parent = next;
	if (next != NULL && next->right != NULL)
		next->right->parent = next;
	if (next->parent == NULL)
		return (next);
	return (root);
}
