#include "binary_trees.h"

#define NULL ((void *)0)


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
