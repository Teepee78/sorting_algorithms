#include "sort.h"

/**
 * counting_sort - counting sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int index;
	size_t i, j, largest_num;
	count_t *count_array = NULL;
	int *output = NULL;

	if (!array || size < 2)
		return;
	largest_num = largest_number(array, size);
	count_array = malloc(sizeof(count_t) * (largest_num + 1));
	if (count_array == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	/* initialize counting array */
	for (i = 0; i <= largest_num; i++)
	{
		count_array[i].num = i;
		count_array[i].count = 0;
	}
	/* set counting array */
	for (i = 0; i < size; i++)
	{
		j = array[i];
		count_array[j].count += 1;
	}
	/* sum and print counting array */
	for (i = 1; i <= largest_num; i++)
		count_array[i].count = count_array[i].count + count_array[i - 1].count;
	/* create output array */
	for (i = 0; i < size; i++)
	{
		j = array[i];
		index = count_array[j].count - 1;
		output[index] = array[i];
	}
	/* set sorted array */
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output), free(count_array);
}

/**
 * largest_number - finds the largest number in an array
 * @array: array of integers
 * @size: size of array
 * Return: largest number
 */
size_t largest_number(int *array, size_t size)
{
	size_t i = 0;
	int largest = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}

	return (largest);
}
