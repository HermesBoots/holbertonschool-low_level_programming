#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * retrace_avl - rebalance an AVL tree after altering it
 * @tree: subtree that was altered
 * @side: side that became unbalanced
 * Return: new root of the subtree
 */
avl_t *retrace_avl(avl_t *tree, int side)
{
	int balance;

	if (tree == NULL || tree->parent == NULL)
		return (tree);
	if (tree->parent->left == tree && side == 'l')
		side = 0x11;
	else if (tree->parent->left == tree && side == 'r')
		side = 0x112;
	else if (tree->parent->right == tree && side == 'r')
		side = 0x1212;
	else
		side = 0x121;
	balance = binary_tree_balance(tree->parent);
	if (balance > 1 && side == 0x11)
	{
		tree = binary_tree_rotate_right(tree->parent);
	}
	else if (balance > 1 && side == 0x112)
	{
		tree = binary_tree_rotate_left(tree);
		tree = binary_tree_rotate_right(tree->parent);
	}
	else if (balance < -1 && side == 0x1212)
	{
		tree = binary_tree_rotate_left(tree->parent);
	}
	else if (balance < -1 && side == 0x121)
	{
		tree = binary_tree_rotate_right(tree);
		tree = binary_tree_rotate_left(tree->parent);
	}
	else
	{
		tree = tree->parent;
	}
	return (tree);
}


/**
 * avl_insert - insert a value into an AVL tree, ensuring it remains such
 * @tree: tree to modify
 * @value: value to insert
 * Return: new node containing value, NULL if it couldn't be inserted
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *parent;
	char side;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	node = *tree;
	while (node != NULL && node->n != value)
	{
		parent = node;
		if (node->n > value)
			node = node->left, side = 'l';
		else if (node->n < value)
			node = node->right, side = 'r';
	}
	if (node != NULL)
		return (NULL);
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->parent = parent, node->n = value;
	node->left = NULL, node->right = NULL;
	if (side == 'l')
		parent->left = node;
	else
		parent->right = node;
	if (parent->parent == *tree)
		*tree = retrace_avl(parent, side);
	else
		retrace_avl(parent, side);
	return (node);
}
