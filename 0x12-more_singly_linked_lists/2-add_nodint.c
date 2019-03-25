#include <stdlib.h>
#include "lists.h"


/**
 * add_nodeint - prepend a node to a linked list
 * @head: pointer to pointer to first element in list, points to new first
 * @n: integer to store in new element
 *
 * Return: pointer to new element or NULL if allocation fails
 */
listint_t *add_nodeint(listint_t **head, int const n)
{
	listint_t *node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = *head;
	*head = node;
	return (node);
}
