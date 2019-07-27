#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * do_tree_height - recursive helper function for binary_tree_height
 * @tree: tree to measure
 * @height: height so far
 * Return: height of this branch of the tree
 */
size_t do_tree_height(binary_tree_t const *tree, size_t height)
{
	size_t left = 0, right = 0;

	height++;
	if (tree->left != NULL)
		left = do_tree_height(tree->left, height);
	if (tree->right != NULL)
		right = do_tree_height(tree->right, height);
	if (left == 0 && right == 0)
		return (height);
	return (left > right ? left : right);
}

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: tree to measure
 * Return: height of the tree
 */
size_t binary_tree_height(binary_tree_t const *tree)
{
	if (tree == NULL)
		return (0);
	return (do_tree_height(tree, 0));
}


/**
 * binary_tree_is_bst - check if tree is sorted like a binary search tree
 * @tree: tree to check
 * Return: 1 if tree exists and is a BST, 0 otherwise
 */
int binary_tree_is_bst(binary_tree_t const *tree)
{
	char side = 'x';

	if (tree == NULL)
		return (0);
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			side = 'l';
		else
			side = 'r';
	}
	if (tree->left != NULL)
	{
		if (tree->left->n >= tree->n)
			return (0);
		if (side == 'l' && tree->left->n >= tree->parent->n)
			return (0);
		if (side == 'r' && tree->left->n <= tree->parent->n)
			return (0);
		if (binary_tree_is_bst(tree->left) == 0)
			return (0);
	}
	if (tree->right != NULL)
	{
		if (tree->right->n <= tree->n)
			return (0);
		if (side == 'l' && tree->right->n >= tree->parent->n)
			return (0);
		if (side == 'r' && tree->right->n <= tree->parent->n)
			return (0);
		if (binary_tree_is_bst(tree->right) == 0)
			return (0);
	}
	return (1);
}


/**
 * binary_tree_is_avl - check if a binary tree is an AVL tree
 * @tree: tree to check
 * Return: 1 if the tree is an AVL, 0 if it isn't
 */
int binary_tree_is_avl(binary_tree_t const *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_bst(tree) == 0)
		return (0);
	if (tree->left != NULL)
		left = binary_tree_height(tree->left);
	if (tree->right != NULL)
		right = binary_tree_height(tree->right);
	if ((right - left > left - right ? left - right : right - left) > 1)
		return (0);
	if (tree->left != NULL && binary_tree_is_avl(tree->left) == 0)
		return (0);
	if (tree->right != NULL && binary_tree_is_avl(tree->right) == 0)
		return (0);
	return (1);
}
