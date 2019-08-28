#include <stdio.h>
#include "search_algos.h"


/**
 * linear_skip - search a sorted list with an "express lane"
 * @list: list to search
 * @value: value to search for
 * Return: node in list containing value or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *limit;

	if (list == NULL || (list->next == NULL && list->n != value))
		return (NULL);
	for (limit = list; limit->next != NULL;)
	{
		node = limit;
		if (limit->express != NULL)
		{
			limit = limit->express;
			printf(
				"Value checked at index [%lu] = [%d]\n",
				limit->index,
				limit->n
			);
		}
		else
		{
			while (limit->next != NULL)
				limit = limit->next;
		}
		if (limit->n >= value)
			break;
	}
	printf(
		"Value found between indexes [%lu] and [%lu]\n",
		node->index,
		limit->index
	);
	while (node != limit->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}
