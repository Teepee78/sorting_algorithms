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

/**
 * struct bucket_s - node of bucket
 *
 * @n: number
 * @next: pointer to next node
 */
typedef struct bucket_s
{
	int n;
	struct bucket_s *next;
} bucket_t;

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
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* personal functions */
void QuickSort(int *array, int start, int end, size_t size);
int partition(int *array, int start, int end, size_t size);
int get_gap(size_t size);
listint_t *swap_nodes1(listint_t **list, listint_t *current, listint_t *temp);
listint_t *swap_nodes2(listint_t **list, listint_t *current, listint_t *temp);
size_t largest_number(int *array, size_t size);
void print_struct(count_t *counting_struct, size_t largest_num);
void merge(size_t start, size_t middle, size_t end, int *dest, int *source);
void Merge_Sort(size_t start, size_t end, int *array, int *copy);
void swap(int *array, size_t a, size_t b, size_t size);
void heapify(int *array, size_t size, size_t i, size_t root);
int get_current_digit(int number, int index);
int pop_bucket(bucket_t **bucket);
void bucket_sort(int *array, size_t size, bucket_t **bucket, int position);
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir);
void Bitonic_Sort(int *array, size_t size, size_t low, size_t count, int dir);
void swap_n(int *array, size_t a, size_t b);
int partition_hoare(int *array, int start, int end, size_t size);
void QuickSort_hoare(int *array, int start, int end, size_t size);

#endif /* SOR_T */
