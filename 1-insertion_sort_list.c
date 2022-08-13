#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *key, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current; current = current->next)
	{
		key = current;
		temp = key->prev;
		while (temp && key->n < temp->n)
		{
			/* if key is not the last element */
			if (key->next)
				key->next->prev = temp;
			temp->next = key->next;
			key->next = temp;
			key->prev = temp->prev;
			if (key->prev)
				temp->prev->next = key;
			else
				*list = key;
			temp->prev = key;
			print_list(*list);
			/* go to the prev node */
			temp = key->prev;
		}
	}
}
