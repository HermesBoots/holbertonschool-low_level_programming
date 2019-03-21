#include "lists.h"
#include <stdio.h>


/**
 * print_list - print all strings in a list
 * @h: list to print
 *
 * Return: length of list
 */
size_t print_list(list_t const *h)
{
	size_t ret = 0;

	for (; h != NULL; h = h->next)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
		{
			printf("[%u] %.*s\n", h->len, h->len, h->str);
		}
		ret++;
	}
	return (ret);
}
