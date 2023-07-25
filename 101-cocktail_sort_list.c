#include "sort.h"

/**
 * neo_switch - swap the nodes themselves.
 * @new: pointer.
 * @old: pointer.
 * @list: doubly linked list
 */
void neo_switch(listint_t *new, listint_t *old, listint_t **list)
{
	listint_t *temp1 = new->next;
	listint_t *temp2 = old->prev;

	if (temp1 != NULL)
		temp1->prev = old;
	if (temp2 != NULL)
		temp2->next = new;
	new->prev = temp2;
	old->next = temp1;
	new->next = old;
	old->prev = new;
	if (*list == old)
		*list = new;
	print_list(*list);
}

/**
 * cocktail_sort_list - cocktail_sort_list
 *
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *zb1 = *list, *first = NULL, *last = NULL;

	if (!list)
		return;
	if (!(*list))
		return;
	if (!(*list)->next)
		return;
	do {
		while (zb1->next)
		{
			if (zb1->n > zb1->next->n)
				neo_switch(zb1->next, zb1, list);
			else
				zb1 = zb1->next;
		}
		last = zb1;
		while (zb1->prev != first)
		{
			if (zb1->n < zb1->prev->n)
				neo_switch(zb1, zb1->prev, list);
			else
				zb1 = zb1->prev;
		}
		first = zb1;
	} while (first != last);
}
