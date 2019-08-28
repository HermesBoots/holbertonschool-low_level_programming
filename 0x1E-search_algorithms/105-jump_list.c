#include <math.h>
#include <stdio.h>
#include "search_algos.h"


/**
 * jump_list - search a sorted, linked list using jump search
 * @list: pointer to first node in list
 * @size: number of nodes in list
 * @value: value to search for
 * Return: node in list containing value or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *node, *limit;
	size_t counter, gap, index;

	gap = sqrt(size);
	if (list == NULL || (list->next == NULL && list->n != value))
		return (NULL);
	for (index = 0, limit = list; limit->next != NULL;)
	{
		node = limit;
		for (counter = 0; counter < gap && limit->next != NULL; counter++)
			index++, limit = limit->next;
		printf("Value checked at index [%lu] = [%d]\n", index, limit->n);
		if (limit->n >= value)
			break;
	}
	index -= index % gap ? index % gap : gap;
	printf(
		"Value found between indexes [%lu] and [%lu]\n",
		index,
		index + gap < size ? index + gap : size - 1
	);
	for (; node != limit->next; node = node->next, index++)
	{
		printf("Value checked at index [%lu] = [%d]\n", index, node->n);
		if (node->n == value)
			return (node);
	}
	return (NULL);
}
