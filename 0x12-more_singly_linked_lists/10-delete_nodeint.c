#include <limits.h>
#include <stdlib.h>
#include "lists.h"


/**
 * delete_nodeint_at_index - delete a node at a given index in a linked list
 * @head: pointer to pointer to first element
 * @index: index of element to delete
 *
 * Return: 1 if node existed, -1 if it didn't
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		node = (*head)->next;
		free(*head);
		*head = node;
	}
	else
	{
		index--;
		while ((*head)->next != NULL && index--)
			head = &(*head)->next;
		if (index != UINT_MAX)
			return (-1);
		node = (*head)->next->next;
		free((*head)->next);
		(*head)->next = node;
	}
	return (1);
}
