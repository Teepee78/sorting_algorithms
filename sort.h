#ifndef SOR_T
#define SOR_T

#include <stddef.h>
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

/**
 * struct count_s - struct of number count
 *
 * @num: number
 * @count: number count
 */
typedef struct count_s
{
	int num;
	int count;
} count_t;

/* Given functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting Algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);

/* personal functions */
void QuickSort(int *array, int start, int end, size_t size);
int partition(int *array, int start, int end, size_t size);
int get_gap(size_t size);
listint_t *swap_nodes1(listint_t **list, listint_t *current, listint_t *temp);
listint_t *swap_nodes2(listint_t **list, listint_t *current, listint_t *temp);
size_t largest_number(int *array, size_t size);

#endif /* SOR_T */
