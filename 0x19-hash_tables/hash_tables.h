/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;


hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(unsigned char const *str);
unsigned long int key_index(unsigned char const *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, char const *key, char const *value);
int add_node(hash_node_t **list, char const *key, char const *value);
int update_node(hash_node_t *previous, hash_node_t *node, char const *value);
char *hash_table_get(hash_table_t const *ht, char const *key);
