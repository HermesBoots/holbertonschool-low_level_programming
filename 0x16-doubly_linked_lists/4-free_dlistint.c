#include <stdlib.h>
#include "lists.h"


/**
 * free_dlistint - free an entire doubly-linked list
 * @head: first node in list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
