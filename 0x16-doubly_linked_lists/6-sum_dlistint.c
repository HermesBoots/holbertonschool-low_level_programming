#include "lists.h"


/**
 * sum_dlistint - sum values in a doubly-linked list
 * @head: first node in list
 *
 * Return: sum of data in list
 */
int sum_dlistint(dlistint_t *head)
{
	int ret = 0;

	while (head != NULL)
	{
		ret += head->n;
		head = head->next;
	}
	return (ret);
}
