#include "sort.h"

/**
 * swap_node - swaps two nodes
 * @node1: pointer to one o the nodes
 * @node2: pointer to the other node
 * @list: pointer to the head of the linked list which contains the nodes
 */
void swap_node(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *tmp = (*node1)->prev;

	(*node1)->next = (*node2)->next;
	if ((*node2)->next != NULL)
		(*node2)->next->prev = *node1;

	(*node1)->prev = *node2;
	(*node2)->next = *node1;
	(*node2)->prev = tmp;

	if ((*node2)->prev != NULL)
		(*node2)->prev->next = *node2;
	else
		*list = *node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: a pointer to the head of the doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *key = NULL;

	if (!list || !(*list))
		return;

	for (tmp = *list; tmp != NULL; tmp = tmp->next)
	{
		while (tmp->next != NULL && tmp->n > tmp->next->n)
		{
			key = tmp->next;
			while (key->prev != NULL && key->n < key->prev->n)
			{
				swap_node(list, &key->prev, &key);
				print_list(*list);
			}
		}
	}


}
