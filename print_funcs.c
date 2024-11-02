#include "sort.h"

/**
 * print_array - Displays elements of an integer array
 * @array: Source array to print
 * @size: Number of elements in array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	if (!array || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * print_list - Shows elements of a doubly linked list
 * @list: Pointer to first node of list
 */
void print_list(const listint_t *list)
{
	if (!list)
		return;

	while (list)
	{
		printf("%d", list->n);
		list = list->next;
		if (list)
			printf(", ");
	}
	printf("\n");
}
