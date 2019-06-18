#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sort doubly linked list via insertion sort
 * @list: double pointer to a dll
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *fp, *cfp, *bp;

	if (list == NULL || *list == NULL)
		return;
	for (cfp = fp = (*list)->next; cfp != NULL; cfp = fp = cfp->next)
	{
		if (fp->prev->n <= fp->n)
			continue;
		cfp = fp->prev;
		for (bp = fp->prev; bp != NULL && fp->n < bp->n; bp = fp->prev)
		{
			if (fp->next != NULL)
				fp->next->prev = bp;
			bp->next = fp->next;
			fp->next = bp;
			fp->prev = bp->prev;
			if (bp->prev != NULL)
				bp->prev->next = fp;
			else
				*list = fp;
			bp->prev = fp;
			print_list(*list);
		}
	}
}
