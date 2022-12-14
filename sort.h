#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

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
/* prototype */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(listint_t **list, listint_t *current, listint_t *previous, int count);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void recursive_quicksort(int *arr, size_t size, ssize_t lo, ssize_t hi);
ssize_t partition(int *arr, size_t size, ssize_t lo, ssize_t hi);
#endif
