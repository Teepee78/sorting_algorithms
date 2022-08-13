#include "sort.h"

/**
 * shell_sort - shell sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int gap = get_gap(size), temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	/* iterate list and swap necessary values till gap is 1*/
	while (gap > 0)
	{
		for (i = 0; i < size && (i + gap) < size; i++)
		{
			j = i + gap;
			while (j < size)
			{
				/* compare the two values */
				if (array[j] < array[i])
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
				j = j + gap;
			}
		}
		gap = gap / 3;
		print_array(array, size);
	}
}

/**
 * get_gap - get knuth sequence gap
 * @size: size of array
 * Return: gap
 */
int get_gap(size_t size)
{
	int gap, intsize = size;

	/* get gap (interval) using knuth sequence */
	for (gap = 1; gap < intsize / 3; gap = (gap * 3) + 1)
	{}

	return (gap);
}
