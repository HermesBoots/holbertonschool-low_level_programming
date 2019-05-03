#include <stdlib.h>
#include "lists.h"


/**
 * delete_dnodeint_at_index - delete a node from a list at a specified index
 * @head: first node in list
 * @index: index of node to delete
 *
 * Return: 1 if node existed, -1 if it didn't
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (head == NULL)
		return (-1);
	i = index;
	node = *head;
	while (i > 0 && node != NULL)
	{
		node = node->next;
		i--;
	}
	if (node == NULL)
		return (-1);
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (index == 0)
		*head = node->next;
	free(node);
	return (1);
}
