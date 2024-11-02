/* 102-counting_sort.c */
#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: Array to search
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - Sorts array using Counting sort
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max, i;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
