#include "sort.h"

/**
 * merge_sort -  merge sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (size < 2)
		return;

	/* copy array */
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];

	Merge_Sort(0, size, array, copy);
	free(copy);
}

/**
 * Merge_Sort - Merge sort function
 * @start: start index
 * @end: end index
 * @array: array
 * @copy: array copy
 */
void Merge_Sort(size_t start, size_t end, int *array, int *copy)
{
	size_t i, middle;

	if (end - start < 2)
		return;

	middle = (start + end) / 2;

	Merge_Sort(start, middle, array, copy);
	Merge_Sort(middle, end, array, copy);
	merge(start, middle, end, array, copy);
	for (i = start; i < end; i++)
		copy[i] = array[i];
}

/**
 * merge - sorts and merges the sub arrays in source
 * @start: starting index (inclusive) for the left sub array
 * @middle: end index (exclusive) for the left sub array and
 * starting index (inclusive) for the right sub array
 * @end: end index (exclusive) for the right sub array
 * @dest: destination for data
 * @source: source of data
 * Return: void
 */
void merge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);

	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		} else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}
