#include <string.h>
#include "hash_tables.h"


/**
 * hash_table_get - retrive a value from the hash map
 * @ht: hash table to search
 * @key: key of value to retrieve
 *
 * Return: value string if found, NULL otherwise
 */
char *hash_table_get(hash_table_t const *ht, char const *key)
{
	hash_node_t *node;

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
