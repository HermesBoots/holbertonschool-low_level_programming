#include "binary_trees.h"

#define NULL ((void *)0)


/**
 * binary_trees_ancestor - find the lowest common ancestor of two tree nodes
 * @first: first node
 * @second: second node
 * Return: common ancestor or NULL if there is none
 */
binary_tree_t *binary_trees_ancestor(
	binary_tree_t const *first,
	binary_tree_t const *second
)
{
	binary_tree_t const *parent1, *parent2;
	size_t depth1, depth2;

	if (first == NULL || second == NULL)
		return (NULL);
	depth1 = binary_tree_depth(first);
	depth2 = binary_tree_depth(second);
	parent1 = first, parent2 = second;
	while (depth1 > depth2)
	{
		parent1 = parent1->parent;
		depth1--;
	}
	while (depth2 > depth1)
	{
		parent2 = parent2->parent;
		depth2--;
	}
	while (parent1 != NULL && parent2 != NULL)
	{
		if (parent1 == parent2)
			return ((binary_tree_t *)parent1);
		parent1 = parent1->parent;
		parent2 = parent2->parent;
	}
	return (NULL);
}
