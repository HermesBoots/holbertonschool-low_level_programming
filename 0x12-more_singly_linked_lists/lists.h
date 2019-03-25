#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdlib.h>


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */

typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;


size_t print_listint(listint_t const *h);
size_t listint_len(listint_t const *h);


#endif
