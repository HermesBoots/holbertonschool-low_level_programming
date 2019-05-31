#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"


/**
 * shash_table_create - create ordered hash map
 * @size: number of buckets in hash table
 *
 * Return: new hash map, NULL if allocation fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ret;

	ret = calloc(sizeof(shash_table_t) + sizeof(shash_node_t *) * size, 1);
	if (ret == NULL)
		return (NULL);
	ret->array = (shash_node_t **)(ret + 1);
	ret->size = size;
	return (ret);
}

/**
 * shash_table_set - add or update a value in an ordered hash map
 * @ht: map to change
 * @key: key to search for
 * @value: value to insert
 *
 * Return: 1 if update successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, char const *key, char const *value)
{
	shash_node_t **list;
	shash_node_t *previous = NULL, *node;

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
			return (update_snode(list, node, value));
		return (update_snode(&previous->next, node, value));
	}
	node = add_snode(list, key, value);
	if (node == NULL)
		return (0);
	order_snode(ht, node);
	return (1);
}

/**
 * add_snode - add new node to the beginning of a bucket in an ordered hash map
 * @list: bucket to add node to
 * @key: node's key
 * @val: node's value
 *
 * Return: new node if added successfully, NULL otherwise
 */
shash_node_t *add_snode(shash_node_t **list, char const *key, char const *val)
{
	shash_node_t *node;
	size_t key_len, val_len;

	key_len = strlen(key), val_len = strlen(val);
	node = malloc(sizeof(shash_node_t) + key_len + val_len + 2);
	if (node == NULL)
		return (NULL);
	node->key = (char *)(node + 1);
	node->value = node->key + key_len + 1;
	strcpy(node->key, key);
	strcpy(node->value, val);
	node->next = *list;
	*list = node;
	return (node);
}

/**
 * update_snode - update existing node in ordered hash map
 * @previous: the previous node's pointer to this one
 * @node: node to update
 * @val: value to put in node
 *
 * Return: 0 if reallocation fails, 1 otherwise
 */
int update_snode(shash_node_t **previous, shash_node_t *node, char const *val)
{
	size_t key_len, val_len;

	key_len = strlen(node->key), val_len = strlen(val);
	if (val_len > strlen(node->value))
	{
		node = realloc(
			node,
			sizeof(shash_node_t) + val_len + key_len + 2
		);
		if (node == NULL)
			return (0);
		node->key = (char *)(node + 1);
		node->value = node->key + key_len + 1;
		*previous = node;
	}
	strcpy(node->value, val);
	return (1);
}

/**
 * order_snode - sort a newly-created node in an ordered hash map
 * @map: map to order node in
 * @node: node to order
 */
void order_snode(shash_table_t *map, shash_node_t *node)
{
	shash_node_t *next;

	if (map->shead == NULL)
	{
		node->sprev = NULL;
		node->snext = NULL;
		map->shead = node;
		map->stail = node;
		return;
	}
	for (next = map->shead; next != NULL; next = next->snext)
	{
		if (strcmp(next->key, node->key) > 0)
			break;
	}
	if (next == NULL)
	{
		node->sprev = map->stail;
		node->snext = NULL;
		map->stail->snext = node;
		map->stail = node;
		return;
	}
	node->snext = next;
	node->sprev = next->sprev;
	next->sprev = node;
	if (next == map->shead)
		map->shead = node;
	else
		node->sprev->snext = node;
}

/**
 * shash_table_get - retrieve a value from an ordered hash map
 * @ht: map to retrieve from
 * @key: key of value to retrieve
 *
 * Return: value of key or NULL if key not found
 */
char *shash_table_get(shash_table_t const *ht, char const *key)
{
	shash_node_t *node;

	if (ht == NULL || ht->size < 1 || key == NULL || *key == '\0')
		return (NULL);
	node = ht->array[key_index((unsigned char *)key, ht->size)];
	while (node != NULL)
	{
		if (strcmp(key, node->key) == 0)
			break;
		node = node->next;
	}
	if (node == NULL)
		return (NULL);
	return (node->value);
}

/**
 * shash_table_print - print nodes from an ordered hash map in order
 * @ht: map to print
 */
void shash_table_print(shash_table_t const *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	putchar('{');
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print nodes from an ordered hash map backward
 * @ht: map to print
 */
void shash_table_print_rev(shash_table_t const *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	putchar('{');
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - delete an entire ordered hash map
 * @ht: map to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *next, *node;

	if (ht == NULL)
		return;
	for (node = ht->shead; node != NULL; node = next)
	{
		next = node->snext;
		free(node);
	}
	free(ht);
}
