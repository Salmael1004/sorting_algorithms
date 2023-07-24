#include "sort.h"

/**
 * selection_sort - sort list with selection_sort
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, cz, less, zb1, base;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		for (less = i, cz = i; cz < size; cz++)
			if (array[cz] < array[less])
			{
				less = cz;
				base = 1;
			}
		if (base == 1)
		{
			zb1 = array[less];
			array[less] = array[i];
			array[i] = zb1;
			print_array(array, size);
			base = 0;
		}
	}
}
