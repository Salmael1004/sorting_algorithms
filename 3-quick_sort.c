#include "sort.h"

/**
 * quick_sort - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_recu(array, 0, size - 1, size);
}

/**
 * q_recu - helper function for Quicksort
 * @array: array to sort
 * @low: index of the leftmost element
 * @high: index of the rightmost element
 * @size: size of the array
 */
void q_recu(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int zb1 = q_part(array, low, high, size);

		q_recu(array, low, zb1 - 1, size);
		q_recu(array, zb1 + 1, high, size);
	}
}

/**
 * q_part - finds a pivot index for Quicksort
 * @array: array to find the pivot in
 * @low: index of the leftmost element
 * @high: index of the rightmost element
 * @size: size of the array
 *
 * Return: the index of the zb1 element
 */
int q_part(int *array, int low, int high, size_t size)
{
	int zb1 = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= zb1)
		{
			i++;
			if (i != j)

			{
				int tmp = array[i];

				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[high] != array[i + 1])
	{
		int tmp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
