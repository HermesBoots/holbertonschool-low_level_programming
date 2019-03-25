#include <stdlib.h>
#include "lists.h"


/**
 * free_listint2 - free a linked list and set the pointer to it to NULL
 * @head: pointer to pointer to list
 */
void free_listint2(listint_t **head)
{
	listint_t *next;

	while (*head != NULL)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}
