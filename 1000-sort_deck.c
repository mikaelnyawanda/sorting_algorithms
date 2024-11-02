#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_card_value - Converts card string value to numeric value (0-12)
 * @str: String value of the card
 * Return: Numeric value corresponding to card rank
 */
static int get_card_value(const char *str)
{
	int i;
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, values[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 * card_compare - Comparison function for qsort to compare two cards
 * @a: Pointer to first card node
 * @b: Pointer to second card node
 * Return: Negative if a < b, positive if a > b, 0 if equal
 */
static int card_compare(const void *a, const void *b)
{
	deck_node_t *node1 = *(deck_node_t **)a;
	deck_node_t *node2 = *(deck_node_t **)b;
	int value1, value2;

	if (node1->card->kind != node2->card->kind)
		return (node1->card->kind - node2->card->kind);

	value1 = get_card_value(node1->card->value);
	value2 = get_card_value(node2->card->value);

	return (value1 - value2);
}

/**
 * sort_deck - Sorts a deck of cards by suit and rank
 * @deck: Pointer to pointer to head of deck linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	deck_node_t **array;
	int i, count = 0;

	if (!deck || !*deck)
		return;

	current = *deck;
	while (current)
	{
		count++;
		current = current->next;
	}

	array = malloc(count * sizeof(deck_node_t *));
	if (!array)
		return;

	current = *deck;
	for (i = 0; i < count; i++)
	{
		array[i] = current;
		current = current->next;
	}

	qsort(array, count, sizeof(deck_node_t *), card_compare);

	for (i = 0; i < count; i++)
	{
		array[i]->prev = (i > 0) ? array[i - 1] : NULL;
		array[i]->next = (i < count - 1) ? array[i + 1] : NULL;
	}

	*deck = array[0];
	free(array);
}
