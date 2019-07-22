#include "binary_trees.h"

#define NULL ((void *)0)


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
