#include "lists.h"


/**
 * reverse_listint - reverse a linked list in place
 * @head: pointer to pointer to first element
 *
 * Return: pointer to first element
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current, *previous;

	if (head == NULL || *head == NULL)
		return (NULL);
	previous = NULL;
	current = *head;
	while (current != NULL)
	{
		*head = current->next;
		current->next = previous;
		previous = current;
		current = *head;
	}
	*head = previous;
	return (previous);
}
