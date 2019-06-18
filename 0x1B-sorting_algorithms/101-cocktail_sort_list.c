#include "sort.h"
#include <stdio.h>


/**
 * swap_nodes - swap two adjacent nodes in a dll
 * @left: left most node to swap
 * @right: right most node to swap
 * @list: double pointer to a dll
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	right->prev = left->prev;
	left->prev = right;
	left->next = right->next;
	right->next = left;
	if (left->next != NULL)
		left->next->prev = left;
	if (right->prev == NULL)
		*list = right;
	else
		right->prev->next = right;
}

/**
 * cocktail_sort_list - use cocktail shaker sort to sort a dll
 * @list: pointer to a pointer to a dll
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int num_swaps;

	if (list == NULL || *list == NULL)
		return;
	node = *list;
	do {
		num_swaps = 0;
		for (; node->next != NULL; node = node->next)
		{
			if (node->n > node->next->n)
			{
				swap_nodes(node, node->next, list);
				node = node->prev;
				print_list(*list);
				num_swaps++;
			}
		}
		for (; node->prev != NULL; node = node->prev)
		{
			if (node->n < node->prev->n)
			{
				swap_nodes(node->prev, node, list);
				node = node->next;
				print_list(*list);
				num_swaps++;
			}
		}
	} while (num_swaps != 0);
}
