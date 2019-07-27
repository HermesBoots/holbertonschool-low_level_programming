#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_node - add a new node to a tree
 * @parent: parent of the new node, can be NULL
 * @value: value to store in the new node
 * Return: new node or NULL if allocation fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *leaf;

	leaf = malloc(sizeof(*leaf));
	if (leaf == NULL)
		return (NULL);
	leaf->n = value;
	leaf->left = NULL;
	leaf->right = NULL;
	leaf->parent = parent;
	return (leaf);
}
