#include <stdlib.h>
#include "lists.h"


/**
 * free_listint - free an entire linked list of integers
 * @head: pointer to first element in list
 */
void free_listint(listint_t *head)
{
	listint_t *next;

	for (; head != NULL; head = next)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
