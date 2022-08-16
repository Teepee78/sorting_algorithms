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
 * @dir: direction of sorting, 1 (increasing) 0 (decreasing)
 */
void Bitonic_Sort(int *array, size_t size, size_t low, size_t count, int dir)
{
	int k;

	if (count < 2)
		return;
	k = count / 2;
	printf("Merging [%ld/%ld] (%s):\n", count, size, (dir == 1) ? "UP" : "DOWN");
	print_array(&array[low], count);

	Bitonic_Sort(array, size, low, k, 1);
	Bitonic_Sort(array, size, low + k, k, 0);
	bitonic_merge(array, size, low, count, dir);
	printf("Result [%ld/%ld] (%s):\n", count, size, (dir == 1) ? "UP" : "DOWN");
	print_array(&array[low], count);
}

/**
 * bitonic_merge - bitonic merge functiom
 * @array: array of integers
 * @size: size of array
 * @low: starting index of sub array
 * @count: subarray count
 * @dir: direction of sorting, 1 (increasing) 0 (decreasing)
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir)
{
	int k;
	size_t i;

	if (count < 2)
		return;
	k = count / 2;

	/* increasing order */
	if (dir == 1)
	{
		for (i = low; i < low + k; i++)
		{
			if (array[i] > array[i + k])
				swap_n(array, i, i + k);
		}
	}
	else
	{
		for (i = low; i < low + k; i++)
		{
			if (array[i] < array[i + k])
				swap_n(array, i, i + k);
		}
	}
	bitonic_merge(array, size, low, k, dir);
	bitonic_merge(array, size, low + k, k, dir);
}

/**
 * swap_n - swap elements of array
 * @array: array of integers
 * @a: element a
 * @b: element b
 */
void swap_n(int *array, size_t a, size_t b)
{
	int temp;

	/* swap */
	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
