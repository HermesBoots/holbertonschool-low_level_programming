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
 * binary_tree_balance - compute the balance factor of a binary tree
 * @tree: tree to process
 * Return: height of left branch minus height of right branch
 */
int binary_tree_balance(binary_tree_t const *tree)
{
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}


/**
 * binary_tree_is_perfect - check if all subtrees are balanced and full
 * @tree: tree to process
 * Return: 0 if tree is imperfect or NULL, 1 otherwise
 */
int binary_tree_is_perfect(binary_tree_t const *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right != NULL)
		return (0);
	if (tree->left != NULL && tree->right == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (binary_tree_is_perfect(tree->left) == 0)
		return (0);
	if (binary_tree_is_perfect(tree->right) == 0)
		return (0);
	if (binary_tree_balance(tree) != 0)
		return (0);
	return (1);
}
