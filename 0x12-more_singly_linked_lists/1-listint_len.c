#include <stdlib.h>
#include "lists.h"


/**
 * listint_len - get number of elements in a linked list
 * @h: pointer to first element in list
 *
 * Return: number of elements in list
 */
size_t listint_len(listint_t const *h)
{
	size_t ret;

	for (ret = 0; h != NULL; h = h->next, ret++)
		;
	return (ret);
}
