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

	copy = strdup(str);
	node = malloc(sizeof(list_t));
	if (copy == NULL || node == NULL)
	{
		free(copy);
		free(node);
		return (NULL);
	}
	for (len = 0; copy[len] != '\0'; len++)
		;
	node->str = copy;
	node->len = len;
	node->next = *head;
	*head = node;
	return (node);
}
