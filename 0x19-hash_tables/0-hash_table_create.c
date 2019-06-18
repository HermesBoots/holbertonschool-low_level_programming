#include <stdlib.h>
#include "hash_tables.h"


/**
 * hash_table_create - make new hash table with given bucket count
 * @size: number of buckets to allocate
 *
 * Return: pointer to new table or NULL if allocation failed
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ret;

	ret = calloc(sizeof(*ret) + sizeof(hash_node_t *) * size, 1);
	if (ret == NULL)
		return (NULL);
	ret->array = (hash_node_t **)(ret + 1);
	ret->size = size;
	return (ret);
}
