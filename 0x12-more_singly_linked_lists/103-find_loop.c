#include "lists.h"


/**
 * do_find_cycle - find the cycle in a linked list
 * @node: current node
 *
 * Return: pointer to start of cycle or NULL if there is none
 */
listint_t *do_find_cycle(listint_t *node)
{
	listint_t *ret;

	if (node == NULL)
		return (NULL);
	if (((int *)node)[1] == 1)
		return (node);
	((int *)node)[1] = 1;
	ret = do_find_cycle(node->next);
	((int *)node)[1] = 0;
	return (ret);
}


/**
 * find_listint_loop - find the cycle in a linked list
 * @head: pointer to first element
 *
 * Return: pointer to start of cycle or NULL if there isn't one
 */
listint_t *find_listint_loop(listint_t *head)
{
	return (do_find_cycle(head));
}
