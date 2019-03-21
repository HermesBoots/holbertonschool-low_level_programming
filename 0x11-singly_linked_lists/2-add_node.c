#include "lists.h"
#include <string.h>


/**
 * add_node - prepend a node to a list with a copy of a string
 * @head: list to modify
 * @str: string to copy into new node
 *
 * Return: pointer to new element, NULL if allocation fails
 */
list_t *add_node(list_t **head, char const *str)
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
		node->len = len;
		node->str = copy;
	}
	node->next = *head;
	*head = node;
	return (node);
}
