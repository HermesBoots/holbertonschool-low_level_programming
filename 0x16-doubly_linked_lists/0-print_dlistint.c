#include <stdio.h>
#include "lists.h"


/**
 * print_dlistint - print contents of list
 * @h: first node in list
 *
 * Return: number of nodes in list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t ret = 0;

	while (h != NULL)
	{
		printf("%i\n", h->n);
		ret++;
		h = h->next;
	}
	return (ret);
}
