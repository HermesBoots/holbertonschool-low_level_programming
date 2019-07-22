#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_insert_left - insert a new node as the left child of another
 * @parent: new node's parent, NULL is not allowed
 * @value: value to store in new node
 * Return: new node or NULL if parent is NULL or if allocation fails
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t leaf;

	if (parent == NULL)
		return (NULL);
	leaf = malloc(sizeof(*leaf));
	if (leaf == NULL)
		return (NULL);
	leaf->n = value;
	leaf->parent = parent;
	leaf->left = parent->left;
	leaf->right = NULL;
	parent->left = leaf;
	return (leaf);
}
