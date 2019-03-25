#include <limits.h>
#include "lists.h"


/**
 * get_nodeint_at_index - get node at given index in a linked list
 * @head: pointer to first element in list
 * @index: index of element to return
 *
 * Return: pointer to element or NULL if element doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	while (head != NULL && index--)
		head = head->next;
	if (index != UINT_MAX)
		return (NULL);
	return (head);
}
