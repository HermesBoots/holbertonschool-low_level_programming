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
	size_t len, ret = 0;

	for (; h != NULL; h = h->next)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
		{
			for (len = 0; h->str[len] != '\0'; len++)
				;
			printf("[%lu] %s\n", len, h->str);
		}
		ret++;
	}
	return (ret);
}
