#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_tree_uncle - get the uncle of a node in a binary tree
 * @node: node to get uncle of
 * Return: uncle if node and uncle are not NULL, NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
