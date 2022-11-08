#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order using
 * insertion algorithm
 *
 * @list: address of head node of double linked list being sorted
 * Return: nothing sorts in place
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *previous = NULL, *next = NULL;
	int count = 0;

	current = *list;
	if (current == NULL)
		return;
	while (current)
	{
		current = current->next;
		count++;
	}
	current = *list;
	if (count >= 2)
	{
		while (current)
		{
			next  = current->next;
			previous = current->prev;
			while (previous)
			{
				if (current->n < previous->n)
				{
					swap(list, current, previous);
					print_list(*list);
				}
				previous = previous->prev;
			}
			current = next;
		}
	}
}

/**
 * swap - exchanges two out of ascending order nodes of a doubly linked list
 * to their respective in order places
 *
 * @current: out of order integer supposed to be in @previous's place
 * @previous: out of order integer supposed to be in @current's place
 * @list: The address of the headnode of the linked list
 *
 * Return: exchanges out of place with no extra memory
 */
void swap(listint_t **list, listint_t *current, listint_t *previous)
{
	if (previous->prev == NULL)
	{
		previous->next = current->next;
		current->next->prev = previous;
		current->prev = previous->prev;
		previous->prev = current;
		current->next = previous;
		*list = current;
	}
	else if (current->next == NULL)
	{
		previous->next = current->next;
		current->prev = previous->prev;
		previous->prev->next = current;
		previous->prev = current;
		current->next = previous;
	}
	else
	{
		previous->next = current->next;
		current->next->prev = previous;
		current->prev = previous->prev;
		previous->prev->next = current;
		previous->prev = current;
		current->next = previous;
	}
}
