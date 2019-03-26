#include <limits.h>
#include <stdlib.h>
#include "lists.h"


/**
 * insert_nodeint_at_index - insert new node in list at given index
 * @head: pointer to pointer to first element in list
 * @idx: index to insert new node into
 * @n: value to store in new node
 *
 * Return: pointer to new node, NULL If it doesn't fit or allocation failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node = NULL;

	if (head == NULL)
		return (NULL);
	if (idx == 0)
	{
		node = malloc(sizeof(*node));
		if (node == NULL)
			return (NULL);
		node->n = n;
		((int *)node)[1] = 0;
		if (*head != NULL)
			node->next = *head;
		else
			node->next = NULL;
		*head = node;
	}
	else
	{
		if (*head == NULL)
			return (NULL);
		idx--;
		while (idx-- && (*head)->next != NULL)
			head = &(*head)->next;
		if (idx != UINT_MAX)
			return (NULL);
		node = malloc(sizeof(*node));
		if (node == NULL)
			return (NULL);
		node->n = n;
		((int *)node)[1] = 0;
		node->next = (*head)->next;
		(*head)->next = node;
	}
	return (node);
}
