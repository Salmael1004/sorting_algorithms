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

	quick_recursion(array, 0, size - 1, size);
}

/**
 * quick_recursion - helper function for Quicksort
 * @array: array to sort
 * @low: index of the leftmost element
 * @high: index of the rightmost element
 * @size: size of the array
 */
void quick_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quick_recursion(array, low, pivot - 1, size);
		quick_recursion(array, pivot + 1, high, size);
	}
}

/**
 * partition - finds a pivot index for Quicksort
 * @array: array to find the pivot in
 * @low: index of the leftmost element
 * @high: index of the rightmost element
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
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
