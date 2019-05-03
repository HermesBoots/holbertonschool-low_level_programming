#ifndef _LISTS_H_
#define _LISTS_H_


/**
 * struct dlistint_s - doubly linked list
 * @n: data
 * @prev: pointer to previous node
 * @next: pointer to next node
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;


size_t print_dlistint(const dlistint_t *h);


#endif
