#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"


/**
 * hash_table_set - add or update a value in the hash table
 * @ht: table to change
 * @key: key to search for
 * @value: value to set
 *
 * Return: 1 if value successfully added, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, char const *key, char const *value)
{
	hash_node_t **list;
	hash_node_t *previous = NULL, *node;

	if (ht == NULL || ht->size < 1)
		return (0);
	if (key == NULL || value == NULL || *key == '\0')
		return (0);
	list = &ht->array[key_index((unsigned char *)key, ht->size)];
	for (node = *list; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			break;
		previous = node;
	}
	if (node != NULL)
	{
		if (previous == NULL)
			return (update_node(list, node, value));
		return (update_node(&previous->next, node, value));
	}
	return (add_node(list, key, value));
}


/**
 * add_node - add a new node to the beginning of the bucket
 * @list: bucket to add node to
 * @key: node's key
 * @value: node's value
 *
 * Return: 0 if allocation failed, 1 otherwise
 */
int add_node(hash_node_t **list, char const *key, char const *value)
{
	hash_node_t *node;
	size_t key_len, val_len;

	key_len = strlen(key), val_len = strlen(value);
	node = malloc(sizeof(hash_node_t) + key_len + val_len + 2);
	if (node == NULL)
		return (0);
	node->key = (char *)(node + 1);
	node->value = node->key + key_len + 1;
	strcpy(node->key, key);
	strcpy(node->value, value);
	node->next = *list;
	*list = node;
	return (1);
}


/**
 * update_node - update the value in an existing node in a bucket
 * @previous: the previous node's pointer to this one
 * @node: node to update
 * @value: value to put in node
 *
 * Return: 0 if reallocation of value failes, 1 otherwise
 */
int update_node(hash_node_t **previous, hash_node_t *node, char const *value)
{
	size_t key_len, val_len;

	key_len = strlen(node->key), val_len = strlen(value);
	if (val_len > strlen(node->value))
	{
		node = realloc(
			node,
			sizeof(hash_node_t) + val_len + key_len + 2
		);
		if (node == NULL)
			return (0);
		node->key = (char *)(node + 1);
		node->value = node->key + key_len + 1;
		*previous = node;
	}
	strcpy(node->value, value);
	return (1);
}
