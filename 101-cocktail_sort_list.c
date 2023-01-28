#include "sort.h"

void swap_(listint_t *left, listint_t *right, listint_t **head);
/**
 * swap_ - swaps the nodes
 * @left: left or lower node
 * @right: right or upper node
 * @head: head of the linked list
 */
void swap_(listint_t *left, listint_t *right, listint_t **head)
{
	listint_t *temp = left->prev;

	if (temp)
		temp->next = right;

	right->prev = temp;
	left->prev = right;
	left->next = right->next;
	right->next = left;

	if (left->next != NULL)
		left->next->prev = left;

	if (right->prev == NULL)
		(*head) = right;

	print_list(*head);
}

/**
 * cocktail_sort_list - implements the cocktail sort algorithm
 * @list: the linked list being sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL;
	bool swap = true;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	while (swap)
	{
		swap = false;
		temp = (*list);

		while (temp->next != NULL)
		{
			if (temp->next)
			{
				if (temp->n > temp->next->n)
				{
					swap_(temp, temp->next, list);
					swap = true;
				}
				else
					temp = temp->next;
			}
		}

		if (!swap)
			break;

		temp = temp->prev;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap_(temp->prev, temp, list);
				swap = true;
			}
			else
				temp = temp->prev;
		}
	}
}
