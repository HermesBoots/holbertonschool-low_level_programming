#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_sibling - get the sibling node of a given node
 * @node: node to get sibling of
 * Return: sibling if node and the sibling are not NULL, NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
