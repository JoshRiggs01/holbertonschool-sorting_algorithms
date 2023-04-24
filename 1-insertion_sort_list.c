#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: pointer to pointer where list is
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list;

	while (curr)
	{
		while (curr->prev && curr->prev->n > curr->n)
		{
			curr->prev->next = curr->next;
			if (curr->next)
			{
				curr->next->prev = curr->prev;
			}
			curr->next = curr->prev;
			curr->prev = curr->prev->prev;
			curr->next->prev = curr;
			if (curr->prev)
			{
				curr->prev->next = curr;
			}
			else
			{
				*list = curr;
			}
			print_list(*list);
			printf("\n");
		}
		curr = curr->next;
	}
}
