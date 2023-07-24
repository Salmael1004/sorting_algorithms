#include "sort.h"
/**
* insertion_sort_list - insertion sorting algorithm
* @list: linked list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *zb1;
	int neo;

	if (!list)
		return;
	zb1 = *list;
	while (zb1)
	{
		while (zb1)
		{
			if (zb1->next)
			{
				if (zb1->n > zb1->next->n)
				{
					neo = zb1->n;
					*(int *)&zb1->n = zb1->next->n;
					*(int *)&zb1->next->n = neo;
					zb1 = *list;
					print_list(*list);
					break;
				}
			}
			zb1 = zb1->next;
		}
	}
}
