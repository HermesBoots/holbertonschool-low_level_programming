#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_is_leaf - check if a node in a tree is childless
 * @node: node to check
 * Return: 0 if node has children or is NULL, 1 otherwise
 */
int binary_tree_is_leaf(binary_tree_t const *node)
{
	return (node != NULL && node->left == NULL && node->right == NULL);
}
