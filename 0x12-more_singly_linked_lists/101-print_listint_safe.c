#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * do_print_list - use recursion to safely print a linked list
 * @node: current node in list
 * @count: number of nodes so far
 *
 * Return: number of elements in list
 */
size_t do_print_list(listint_t *node, size_t count)
{
	size_t ret;

	if (node == NULL)
		return (count);
	if (((int *)node)[1] == 1)
	{
		printf("-> [%p] %d\n", (void *)node, node->n);
		return (count);
	}
	((int *)node)[1] = 1;
	printf("[%p] %d\n", (void *)node, node->n);
	ret = do_print_list(node->next, count + 1);
	((int *)node)[1] = 0;
	return (ret);
}



/**
 * print_listint_safe - print a linked list, even if it contains a loop
 * @head: pointer to first element
 *
 * Return: number of elements in list
 */
size_t print_listint_safe(listint_t const *head)
{
	return (do_print_list((listint_t *)head, 0));
}
