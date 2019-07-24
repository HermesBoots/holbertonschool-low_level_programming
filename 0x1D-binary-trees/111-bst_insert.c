#include <stdlib.h>
#include "binary_trees.h"


/**
 * bst_insert - insert a value into a binary search tree
 * @tree: tree to modify
 * @value: value to insert
 * Return: pointer to new node if it was inserted, NULL otherwise
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *search;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	new = *tree;
	while (new != NULL && new->n != value)
	{
		search = new;
		if (new->n > value)
			new = new->left;
		else if (new->n < value)
			new = new->right;
	}
	if (new != NULL)
		return (NULL);
	if (search->n > value)
		return (binary_tree_insert_left(search, value));
	return (binary_tree_insert_right(search, value));
}
