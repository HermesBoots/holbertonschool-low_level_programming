#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

/**
 * struct listint_s - simple linked list nodes
 * @n: value in the nodes
 * @index: index in the list
 * @next: pointer to next node in the list
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);

#endif
