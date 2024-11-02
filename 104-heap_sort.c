/* 104-heap_sort.c */
#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: Array to sort
 * @start: Start index
 * @end: End index
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;
	int temp;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			temp = array[root];
			array[root] = array[child];
			array[child] = temp;
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts array using Heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (!array || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; i--)
		sift_down(array, i, size - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
