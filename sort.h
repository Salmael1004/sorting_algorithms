#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>

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


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void q_recu(int *array, int left, int right, size_t size);
int q_part(int *array, int left, int right, size_t size);
void shell_sort(int *array, size_t size);
void neo_switch(listint_t *new, listint_t *old, listint_t **list);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_recu(int *zb1, int *array, size_t left, size_t right);
void merge_sub(int *zb1, int *array, size_t left,
		size_t middle, size_t right);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t s, size_t root, size_t size);

void neo_swap(int *a, int *b);
void heapi(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

void radix_sort(int *array, size_t size);

#endif
