#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * print_listint - print a linked list of integers
 * @h: first element of list
 *
 * Return: size of list
 */
size_t print_listint(listint_t const *h)
{
	size_t ret;

	for (ret = 0; h != NULL; h = h->next, ret++)
		printf("%d\n", h->n);
	return (ret);
}
