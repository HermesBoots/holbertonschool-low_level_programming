#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_is_root - check if node is the root of a tree
 * @node: node to check
 * Return: 0 if node has a parent or is NULL, 1 otherwise
 */
int binary_tree_is_root(binary_tree_t const *node)
{
	return (node != NULL && node->parent == NULL);
}
