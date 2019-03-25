#include "lists.h"


/**
 * sum_listint - return sum of all members of a linked list
 * @head: pointer to first element in list
 *
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int ret = 0;

	while (head != NULL)
	{
		ret += head->n;
		head = head->next;
	}
	return (ret);
}
