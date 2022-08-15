#include "sort.h"

/**
 * heap_sort - heap sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* build heap */
	for (i = ((size - 1) / 2) - 1; i > 0; i--)
		heapify(array, size, i, size - 1);
	/* heap sort */
	i = size - 1;
	while (i > 0)
	{
		heapify(array, size, 0, i);
		swap(array, i, 0, size);
		i--;
	}
}

/**
 * heapify - builds a max heap
 * @array: array of integers
 * @size: size of array
 * @i: index of parent element
 * @root: root of heap
 */
void heapify(int *array, size_t size, size_t i, size_t root)
{
	size_t left, right, largest = i;

	if (i == root)
		return;

	left = (2 * i) + 1;
	right = (2 * i) + 2;

	/* get index of largest element */
	if (left <= root && array[left] > array[largest])
		largest = left;
	if (right <= root && array[right] > array[largest])
		largest = right;

	/* swap array[i] with array[largest] if i is not the largest */
	if (i != largest)
	{
		swap(array, i, largest, size);
		heapify(array, size, largest, root);
	}
}

/**
 * swap - swap elements of array
 * @array: array of integers
 * @a: element a
 * @b: element b
 * @size: size of array
 */
void swap(int *array, size_t a, size_t b, size_t size)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	print_array(array, size);
}
