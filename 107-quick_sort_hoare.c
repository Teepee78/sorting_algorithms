#include "sort.h"

/**
 * quick_sort_hoare - quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	QuickSort_hoare(array, 0, size - 1, size);
}

/**
 * QuickSort_hoare - quick sort function
 * @array: array of integers
 * @start: starting index
 * @end: end index
 * @size: size of array
 */
void QuickSort_hoare(int *array, int start, int end, size_t size)
{
	int Pivot;

	if (start < end)
	{
		Pivot = partition_hoare(array, start, end, size);
		QuickSort_hoare(array, start, Pivot, size);
		QuickSort_hoare(array, Pivot + 1, end, size);
	}
}

/**
 * partition_hoare - hoare partition scheme
 * @array: array of integers
 * @start: starting index
 * @end: ending index
 * @size: size of array
 * Return: index of pivot
 */
int partition_hoare(int *array, int start, int end, size_t size)
{
	int pivot, temp;

	pivot = array[end];

	while (start <= end)
	{
		while (array[start] < pivot)
			start++;
		while (array[end] > pivot)
			end--;
		if (start <= end)
		{
			if (start != end)
			{
				temp = array[start];
				array[start] = array[end];
				array[end] = temp;
				print_array(array, size);
			}
			start++;
			end--;
		}
	}
	return (end);
}
