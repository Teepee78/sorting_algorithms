#include "sort.h"

/**
 * quick_sort - quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	QuickSort(array, 0, size - 1, size);
}

/**
 * QuickSort - quick sort function
 * @array: array of integers
 * @start: starting index
 * @end: end index
 * @size: size of array
 */
void QuickSort(int *array, int start, int end, size_t size)
{
	int Pivot;

	if (start < end)
	{
		Pivot = partition(array, start, end, size);
		QuickSort(array, start, Pivot - 1, size);
		QuickSort(array, Pivot + 1, end, size);
	}
}

/**
 * partition - Lomuto partition scheme
 * @array: array of integers
 * @start: starting index
 * @end: ending index
 * @size: size of array
 * Return: index of pivot
 */
int partition(int *array, int start, int end, size_t size)
{
	int Pindex, pivot, i, temp;

	pivot = end;
	Pindex = start;

	for (i = start; i < end; i++)
	{
		if (array[i] < array[pivot])
		{
			if (i != Pindex)
			{
				/* swap values */
				temp = array[i];
				array[i] = array[Pindex];
				array[Pindex] = temp;
				print_array(array, size);
			}
			Pindex++;
		}
	}

	if (array[pivot] < array[Pindex])
	{
		temp = array[Pindex];
		array[Pindex] = array[pivot];
		array[pivot] = temp;
		print_array(array, size);
	}

	return (Pindex);
}
