#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the headof the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *p;

	if (*list == NULL)
		return;
	aux = (*list)->next;
	while (aux != NULL)
	{
		p = aux->next;
		while (aux->prev != NULL && aux->prev->n > aux->n)
		{
			/* exchange of nodes */
			aux->prev->next = aux->next;
			if (aux->next != NULL)
				aux->next->prev = aux->prev;
			aux->next = aux->prev;
			aux->prev = aux->next->prev;
			aux->next->prev = aux;
			if (aux->prev == NULL)
				(*list) = aux;
			else
				aux->prev->next = aux;
			print_list(*list);
		}
		aux = p;
	}
}
