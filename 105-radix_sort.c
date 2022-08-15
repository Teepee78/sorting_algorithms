#include "sort.h"

/**
 * radix_sort - radix sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int largest_num, i, digits = 0;
	bucket_t **bucket;

	if (array == NULL || size < 2)
		return;

	/* find largest number and it's number of digits*/
	largest_num = largest_number(array, size);
	for (i = largest_num; i > 0; i /= 10)
		digits++;
	/* bucket sort */
	bucket = malloc(sizeof(bucket_t) * 10);
	if (bucket == NULL)
		return;
	for (i = 0; i < 10; i++)
		bucket[i] = NULL;
	for (i = 0; i < digits; i++)
		bucket_sort(array, size, bucket, i);
	/* complete this segment */
	free(bucket);
}

/**
 * bucket_sort - bucket sort algorithm
 * @array: array of integers
 * @size: size of array
 * @bucket: bucket to store digits
 * @position: position of digit
 */
void bucket_sort(int *array, size_t size, bucket_t **bucket, int position)
{
	int digit;
	bucket_t *node, *temp;
	size_t i;

	/* set bucket based on position */
	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(bucket_t)); /* create node */
		if (node == NULL)
			return;
		node->n = array[i];
		node->next = NULL;
		digit = get_current_digit(array[i], position);
		if (bucket[digit] == NULL)
			bucket[digit] = node;
		else
		{
			for (temp = bucket[digit]; temp->next != NULL; temp = temp->next)
			{}
			temp->next = node;
		}
	}
	/* update array */
	for (i = 0; i < size; i++)
		array[i] = pop_bucket(bucket);
	print_array(array, size);
}

/**
 * pop_bucket - removes the topmost value from bucket
 * @bucket: bucket
 * Return: topmost value
 */
int pop_bucket(bucket_t **bucket)
{
	int i = 0, n;
	bucket_t *temp;

	while (i < 10)
	{
		temp = bucket[i];
		if (temp != NULL)
		{
			n = temp->n;
			bucket[i] = temp->next;
			free(temp);
			break;
		}
		i++;
	}
	return (n);
}

/**
 * get_current_digit - gets the current digit based on the position of loop
 * @number: number to get digit from
 * @index: position of digit
 * Return: current digit
 */
int get_current_digit(int number, int index)
{
	int j, current_digit, temp_digit;

	if (index == 0)
		current_digit = number % 10;
	else
	{
		temp_digit = number / 10;
		for (j = index - 1; j > 0; j--)
			temp_digit = temp_digit / 10;
		current_digit = temp_digit % 10;
	}

	return (current_digit);
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
