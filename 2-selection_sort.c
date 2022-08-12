#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int current, temp, smallest;

	for (i = 0; i < size; i++)
	{
		current = i;
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}
		if (array[smallest] < array[current])
		{
			temp = array[current];
			array[current] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);
		}
	}
}
