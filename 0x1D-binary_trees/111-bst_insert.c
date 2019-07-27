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
	binary_tree_t *leaf;

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
	if (leaf->left != NULL)
		leaf->left->parent = leaf;
	return (leaf);
}

/**
 * binary_tree_insert_right - insert a new node as the right child of another
 * @parent: new node's parent, NULL is not allowed
 * @value: value to store in new node
 * Return: new node or NULL if parent is NULL or if allocation fails
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *leaf;

	if (parent == NULL)
		return (NULL);
	leaf = malloc(sizeof(*leaf));
	if (leaf == NULL)
		return (NULL);
	leaf->n = value;
	leaf->parent = parent;
	leaf->left = NULL;
	leaf->right = parent->right;
	parent->right = leaf;
	if (leaf->right != NULL)
		leaf->right->parent = leaf;
	return (leaf);
}


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
