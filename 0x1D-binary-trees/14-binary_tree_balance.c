#include <stddef.h>
#include "binary_trees.h"


/**
 * binary_tree_balance - compute the balance factor of a binary tree
 * @tree: tree to process
 * Return: height of left branch minus height of right branch
 */
int binary_tree_balance(binary_tree_t const *tree)
{
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
