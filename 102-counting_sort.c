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

	if (size < 2)
		return;
	largest_num = largest_number(array, size);
	count_array = malloc(sizeof(count_t) * (largest_num + 1));
	if (count_array == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	/* initialize and set counting array */
	for (i = 0; i <= largest_num; i++)
	{
		count_array[i].num = i;
		count_array[i].count = 0;
	}
	for (i = 0; i < size; i++)
	{
		j = array[i];
		count_array[j].count += 1;
	}
	/* sum and print counting array */
	for (i = 1; i <= largest_num; i++)
		count_array[i].count = count_array[i].count + count_array[i - 1].count;
	print_struct(count_array, largest_num);
	/* create output array and set sorted array */
	for (i = 0; i < size; i++)
	{
		j = array[i];
		index = count_array[j].count - 1;
		count_array[j].count--;
		output[index] = array[i];
	}
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
	size_t i;
	int largest = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}

	return (largest);
}

/**
 * print_struct - prints a struct
 * @counting_struct: struct
 * @largest_num: largest nnumber
 */
void print_struct(count_t *counting_struct, size_t largest_num)
{
	int *array;
	size_t i;

	array = malloc(sizeof(int) * (largest_num + 1));
	if (array == NULL)
		return;

	for (i = 0; i <= largest_num; i++)
		array[i] = counting_struct[i].count;

	print_array(array, largest_num + 1);
	free(array);
}
