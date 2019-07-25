#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * bst_search - search for a value in a binary search tree
 * @tree: tree to search in
 * @value: value to search for
 * Return: node containing the value or NULL if it doesn't exist'
 */
bst_t *bst_search(bst_t const *tree, int value)
{
	bst_t const *node;

	node = tree;
	while (node != NULL && node->n != value)
	{
		if (node->n > value)
			node = node->left;
		else if (node->n < value)
			node = node->right;
	}
	return ((bst_t *)node);
}


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
