#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_delete - delete an entire binary tree
 * @tree: tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		binary_tree_delete(tree->left);
	if (tree->right != NULL)
		binary_tree_delete(tree->right);
	if (tree->parent != NULL && tree->parent->left == tree)
		tree->parent->left = NULL;
	free(tree);
}
