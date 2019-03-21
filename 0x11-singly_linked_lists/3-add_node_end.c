#include "lists.h"
#include <string.h>


/**
 * add_node_end - append a new node to a list with a copy of a given string
 * @head: list to modify
 * @str: string to copy into new node
 *
 * Return: pointer to new node or NULL if allocation fails
 */
list_t *add_node_end(list_t **head, char const *str)
{
	char *copy;
	list_t *node;
	size_t len;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);
	if (str == NULL)
	{
		node->str = NULL;
		node->len = 0;
	}
	else
	{
		copy = strdup(str);
		if (copy == NULL)
		{
			free(node);
			return (NULL);
		}
		for (len = 0; copy[len] != '\0'; len++)
			;
		node->str = copy;
		node->len = len;
	}
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		for (; (*head)->next != NULL; head = &((*head)->next))
			;
		(*head)->next = node;
	}
	return (node);
}
