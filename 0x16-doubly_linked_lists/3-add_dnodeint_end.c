#include <stdlib.h>
#include "lists.h"


/**
 * add_dnodeint_end - append new node to list
 * @head: first node in list
 * @n: data to add to new node
 *
 * Return: new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
		return (NULL);
	if (*head != NULL)
	{
		while ((*head)->next != NULL)
			head = &(*head)->next;
	}
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	new->prev = *head;
	if (*head != NULL)
		(*head)->next = new;
	else
		*head = new;
	return (new);
}
