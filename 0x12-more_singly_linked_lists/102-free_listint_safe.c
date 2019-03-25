#include <stdlib.h>
#include "lists.h"


/**
 * do_free_list - free a linked list containing cycles using recursion
 * @node: pointer to current node
 * @count: number of nodes so far
 *
 * Return: number of nodes freed
 */
size_t do_free_list(listint_t *node, size_t count)
{
	size_t ret;

	if (node == NULL || ((int *)node)[1] == 1)
		return (count);
	((int *)node)[1] = 1;
	ret = do_free_list(node->next, count + 1);
	free(node);
	return (ret);
}


/**
 * free_listint_safe - free a linked list, even if it contains cycles
 * @h: pointer to pointer to first node, changed to NULL pointer
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t ret;

	if (h == NULL)
		return (0);
	ret = do_free_list(*h, 0);
	*h = NULL;
	return (ret);
}
