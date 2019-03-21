#include "lists.h"


/**
 * free_list - frees all nodes and strings in a list
 * @head: list to free
 */
void free_list(list_t *head)
{
	list_t *next;

	for (; head != NULL; head = next)
	{
		next = head->next;
		free(head->str);
		free(head);
	}
}
