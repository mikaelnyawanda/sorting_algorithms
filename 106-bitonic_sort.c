/* 106-bitonic_sort.c */
#include "sort.h"

/**
 * bitonic_merge - Merges bitonic sequences
 * @array: Array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: Direction to sort (1 for up, 0 for down)
 * @size: Size of full array
 */
void bitonic_merge(int *array, int low, int count, int dir, size_t size)
{
	int i, temp;
	int k = count / 2;

	if (count > 1)
	{
		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
				print_array(array, size);
			}
		}
		bitonic_merge(array, low, k, dir, size);
		bitonic_merge(array, low + k, k, dir, size);
	}
}

/**
 * bitonic_sort_recursive - Recursive function for bitonic sort
 * @array: Array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: Direction to sort (1 for up, 0 for down)
 * @size: Size of full array
 */
void bitonic_sort_recursive(int *array, int low, int count, int dir, size_t size)
{
	int k = count / 2;

	if (count > 1)
	{
		printf("Merging [%d/%lu] (%s):\n", count, size,
			   dir ? "UP" : "DOWN");
		print_array(array + low, count);

		bitonic_sort_recursive(array, low, k, 1, size);
		bitonic_sort_recursive(array, low + k, k, 0, size);
		bitonic_merge(array, low, count, dir, size);
	}
}

/**
 * bitonic_sort - Sorts array using Bitonic sort
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2 || (size & (size - 1)) != 0)
		return;

	bitonic_sort_recursive(array, 0, size, 1, size);
}
