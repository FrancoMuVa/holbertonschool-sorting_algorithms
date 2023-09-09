#include "sort.h"

/**
 * swap_nodes - function to swap two nodes.
 * @list: doubly linked list.
 * 
 * Return: Nothing.
*/

void swap_nodes(listint_t **list, listint_t *head)
{
	
	if (!(*list)->next)
		return;

	(*list) = (*list)->next;

	while ((*list) && (*list)->prev && (*list)->n < (*list)->prev->n)
	{
		(*list)->prev->next = (*list)->next;

		if ((*list)->next)
			(*list)->next->prev = (*list)->prev;

		(*list)->next = (*list)->prev;

		if ((*list)->prev->prev)
			(*list)->prev->prev->next = (*list);

		(*list)->prev = (*list)->prev->prev;
		(*list)->next->prev = (*list);

		if ((*list)->prev)
			(*list) = (*list)->prev;
		if (!(*list)->prev)
			head = (*list);
		print_list(head);
	}

	if (!(*list)->next)
		return;
	

	swap_nodes(list, head);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order.
 * @list: pointer to doubly linked list.
 * 
 * Return: (Void).
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL;
	
	if (!list)
		return;
	head = malloc(sizeof(listint_t));
	if (!head)
		return;
	head = (*list);
	swap_nodes(list, head);
	while ((*list)->prev)
		(*list) = (*list)->prev;
	return;
}
