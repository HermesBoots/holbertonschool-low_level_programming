#include <stdio.h>
#include "hash_tables.h"


/**
 * hash_table_print - print key-value pairs in the hash table in bucket order
 * @ht: table to print
 */
void hash_table_print(hash_table_t const *ht)
{
	hash_node_t *list, *last;
	unsigned long int index = 0;

	if (ht == NULL)
		return;
	putchar('{');
	for (index = 0; index < ht->size; index++)
	{
		list = ht->array[index];
		if (list != NULL)
			last = list;
	}
	for (index = 0; index < ht->size; index++)
	{
		for (list = ht->array[index]; list != NULL; list = list->next)
		{
			printf("'%s': '%s'", list->key, list->value);
			if (list->next != NULL || list != last)
				printf(", ");
		}
	}
	printf("}\n");
}
