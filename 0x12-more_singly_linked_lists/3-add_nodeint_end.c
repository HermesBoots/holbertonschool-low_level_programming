#include <stdlib.h>
#include "lists.h"


/**
 * add_nodeint_end - append a new element to a linked list
 * @head: pointer to pointer to first element, can be changed
 * @n: value to store in new element
 *
 * Return: pointer to new element, NULL if allocation fails
 */
listint_t *add_nodeint_end(listint_t **head, int const n)
{
	listint_t *node;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->n = n;
	((int *)node)[1] = 0;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		for (; (*head)->next != NULL; head = &(*head)->next)
			;
		(*head)->next = node;
	}
	return (node);
}
