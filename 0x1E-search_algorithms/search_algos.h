#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

#include <stddef.h>

/**
 * struct listint_s - simple linked list nodes
 * @n: value in this node
 * @index: index in the list
 * @next: pointer to next node in the list
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - skip list nodes
 * @n: value in this node
 * @index: index of this node in list
 * @next: pointer to next node in list
 * @express: pointer to node further ahead in list
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
