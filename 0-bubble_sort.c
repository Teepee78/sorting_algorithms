#include "sort.h"

/**
 * bubble_sort - sorts an array with bubble sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, sorted = 0;
	int temp;

	if (size < 2)
		return;

	/* iterate through the list */
	for (i = 0; i < size; i++)
	{
		sorted = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sorted = 1;
				print_array(array, size);
			}
		}
		if (sorted == 0)
			break;
	}
}
