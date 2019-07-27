#include <stddef.h>
#include "binary_trees.h"


/**
 * binary_tree_depth - find the depth of a node in a binary tree
 * @tree: node to process
 * Return: number of ancestors of the node or 0 if tree is NULL
 */
size_t binary_tree_depth(binary_tree_t const *tree)
{
	binary_tree_t *ancestor;
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	for (ancestor = tree->parent; ancestor != NULL; ancestor = ancestor->parent)
		depth++;
	return (depth);
}
