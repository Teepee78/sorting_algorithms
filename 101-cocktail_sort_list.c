#include "sort.h"

/**
 * cocktail_sort_list - cocktail sort algorithm
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *current;
	int sorted = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (sorted == 1)
	{
		sorted = 0;
		/* go forward and bubble sort */
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				current = swap_nodes1(list, current, temp);
				sorted = 1;
				print_list(*list);
			}
		}

		if (sorted == 0)
			break;
		sorted = 0;

		/* go backward and bubble sort */
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev;
				current = swap_nodes2(list, current, temp);
				sorted = 1;
				print_list(*list);
			}
		}
	}
}

/**
 * swap_nodes1 - function to swap nodes
 * @list: doubly linked list
 * @current: current node
 * @temp: next node
 * Return: temp
 */
listint_t *swap_nodes1(listint_t **list, listint_t *current, listint_t *temp)
{
	temp = current->next;
	if (current->prev == NULL)
		*list = temp;
	else
		current->prev->next = temp;
	temp->prev = current->prev;
	current->prev = temp;
	if (temp->next)
		temp->next->prev = current;
	current->next = temp->next;
	temp->next = current;
	return (temp);
}

/**
 * swap_nodes2 - function to swap nodes
 * @list: doubly linked list
 * @current: current node
 * @temp: prev node
 * Return: temp
 */
listint_t *swap_nodes2(listint_t **list, listint_t *current, listint_t *temp)
{
	temp = current->prev;
	if (current->next)
		current->next->prev = temp;
	temp->next = current->next;
	current->next = temp;
	if (temp->prev == NULL)
		*list = current;
	else
		temp->prev->next = current;
	current->prev = temp->prev;
	temp->prev = current;
	return (temp);
}
