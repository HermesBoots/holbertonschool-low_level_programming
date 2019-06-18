#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef size_t st;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap_nodes(listint_t *left, listint_t *right, listint_t **list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
/* void sort_deck(deck_node_t **deck); */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void do_merge_sort(int *, int *, size_t, size_t, size_t);
void do_quick_sort(int *array, size_t size, size_t start, size_t stop);
void fix_heap(int *array, size_t size, size_t root, size_t last);
void do_bitonic_sort(int *, size_t, size_t, size_t, char);

#endif /* SORT_H */
