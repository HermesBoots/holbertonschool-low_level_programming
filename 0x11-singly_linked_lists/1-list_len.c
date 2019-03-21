#include "lists.h"


/**
 * list_len - get the length of a list
 * @h: list to examine
 *
 * Return: length of h
 */
size_t list_len(list_t const *h)
{
	size_t ret = 0;

	for (; h != NULL; h = h->next)
		ret++;
	return (ret);
}
