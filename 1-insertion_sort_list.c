#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: void
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	next = current->next;

	while (next != NULL)
	{
		prev = current;
		next = current->next;
		if (current->n > next->n)
		{
			swap_nodes(current, next, list);
			current = prev;
			print_list(*list);
		}
		current = current->next;
	}
}


/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @current: current node
 * @next: next node
 * @list: doubly linked list
 * Return: void
 */

void swap_nodes(listint_t *current, listint_t *next, listint_t **list)
{
	listint_t *prev, *next_next;

	prev = current->prev;
	next_next = next->next;

	if (prev != NULL)
		prev->next = next;
	else
		*list = next;

	next->prev = prev;
	next->next = current;
	current->prev = next;
	current->next = next_next;

	if (next_next != NULL)
		next_next->prev = current;
}
