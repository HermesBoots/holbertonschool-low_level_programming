#include <stddef.h>
#include "lists.h"


/**
 * dlistint_len - get length of list
 * @h: first node in list
 *
 * Return: number of nodes in list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t ret = 0;

	while (h != NULL)
	{
		ret++;
		h = h->next;
	}
	return (ret);
}
