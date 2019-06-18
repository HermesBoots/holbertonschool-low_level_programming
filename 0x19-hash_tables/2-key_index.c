#include "hash_tables.h"


/**
 * key_index - return index into hash table used by a given key
 * @key: key to hash and insert
 * @size: number of buckets in hash table
 *
 * Return: index of bucket to put key in
 */
unsigned long int key_index(unsigned char const *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
