/* 105-radix_sort.c */
#include "sort.h"

/**
 * get_max_radix - Gets the maximum value in array
 * @array: Array to search
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max_radix(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort_radix - Modified counting sort for radix sort
 * @array: Array to sort
 * @size: Size of array
 * @exp: Current digit place value
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count;
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	count = malloc(sizeof(int) * 10);
	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}

/**
 * radix_sort - Sorts array using Radix sort
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max_radix(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
