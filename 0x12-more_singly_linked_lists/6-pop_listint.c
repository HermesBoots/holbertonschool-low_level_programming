#include <stdlib.h>
#include "lists.h"


/**
 * pop_listint - pop first item from a linked list
 * @head: pointer to pointer to first element
 *
 * Return: integer stored in original first element
 */
int pop_listint(listint_t **head)
{
	int ret;
	listint_t *node;

	if (head == NULL || *head == NULL)
		return (0);
	node = *head;
	*head = node->next;
	ret = node->n;
	free(node);
	return (ret);
}
