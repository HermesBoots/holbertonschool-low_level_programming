#include <stdlib.h>
#include "hash_tables.h"


/**
 * hash_table_delete - delete entire hash map
 * @ht: hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *list, *next;
	unsigned long int index;

	if (ht == NULL)
		return;
	for (index = 0; index < ht->size; index++)
	{
		for (list = ht->array[index]; list != NULL; list = next)
		{
			next = list->next;
			free(list);
		}
	}
	free(ht);
}
