#include "sort.h"

/**
 * bitonic_sort - bitonic sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	Bitonic_Sort(array, size, 0, size, 1);
}

/**
 * Bitonic_Sort - bitonic sort utitlity functiom
 * @array: array of integers
 * @size: size of original array
 * @low: starting index of sub array
 * @count: count of elements in sub array
 * @direction: direction of sorting, 1 (increasing) 0 (decreasing)
 */
void Bitonic_Sort(int *array, size_t size, size_t low, size_t count, int direction)
{
	int k;

	if (count < 2)
		return;
	k = count / 2;
	printf("Merging [%ld/%ld] (UP)\n", count, size);
	print_array(&array[low], count);

	Bitonic_Sort(array, size, low, k, 1);
	Bitonic_Sort(array, size, low + k, k, 0);
	bitonic_merge(array, size, low, count, direction);
}

/**
 * bitonic_merge - bitonic merge functiom
 * @array: array of integers
 * @size: size of array
 * @low: starting index of sub array
 * @count: subarray count
 * @direction: direction of sorting, 1 (increasing) 0 (decreasing)
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int direction)
{
	int k;
	size_t i;

	if (count < 2)
		return;
	k = count / 2;

	/* increasing order */
	if (direction == 1)
	{
		for (i = low; i < low + k; i++)
		{
			if (array[i] > array[i + k])
			{
				printf("Result [%ld/%ld] (UP)\n", count, size);
				swap(array, i, i + k, size);
				print_array(&array[low], count);
			}
		}
	}
	else
	{
		for (i = low; i < low + k; i++)
		{
			if (array[i] < array[i + k])
			{
				printf("Result [%ld/%ld] (DOWN)\n", count, size);
				swap(array, i, i + k, size);
				print_array(&array[low], count);
			}
		}
	}
	bitonic_merge(array, size, low, k, direction);
	bitonic_merge(array, size, low + k, k, direction);
}

/**
 * swap - swap elements of array
 * @array: array of integers
 * @a: element a
 * @b: element b
 * @size: size of array
 */
void swap(int *array, size_t a, size_t b, size_t __attribute__((__unused__))size)
{
	int temp;

	/* swap */
	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}