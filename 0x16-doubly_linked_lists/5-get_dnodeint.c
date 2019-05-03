#include "lists.h"


#define NULL ((void *)0)


/**
 * get_dnodeint_at_index - get node from list at specified index
 * @head: first node in list
 * @index: index to search for
 *
 * Return: note at index if it exists, NULL if it doesn't
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (index > 0 && head != NULL)
	{
		head = head->next;
		index--;
	}
	return (head);
}
