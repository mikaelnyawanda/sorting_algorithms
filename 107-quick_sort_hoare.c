#include "sort.h"

/**
 * swap_print - Swaps two elements and prints the array
 * @array: Array containing elements
 * @size: Size of the array
 * @a: First element to swap
 * @b: Second element to swap
 */
void swap_print(int *array, size_t size, int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}

/**
 * hoare_partition - Implements Hoare partition scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		if (i != j)
			swap_print(array, size, &array[i], &array[j]);
	}
}

/**
 * quick_sort_hoare_recursive - Recursive function for quicksort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = hoare_partition(array, low, high, size);
		quick_sort_hoare_recursive(array, low, pivot, size);
		quick_sort_hoare_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using Quick sort Hoare partition scheme
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}
