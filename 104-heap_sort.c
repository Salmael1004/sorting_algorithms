#include "sort.h"

void neo_swap(int *a, int *b);
void heapi(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * neo_swap - Swap two integers
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void neo_swap(int *a, int *b)
{
	int zb1;

	zb1 = *a;
	*a = *b;
	*b = zb1;
}

/**
 * heapi - binary tree to a complete binary heap
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void heapi(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		neo_swap(array + root, array + large);
		print_array(array, size);
		heapi(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascend order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Implement the sift-down heap sort algorithm
 * Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int zb1;

	if (array == NULL || size < 2)
		return;

	for (zb1 = (size / 2) - 1; zb1 >= 0; zb1--)
		heapi(array, size, size, zb1);

	for (zb1 = size - 1; zb1 > 0; zb1--)
	{
		neo_swap(array, array + zb1);
		print_array(array, size);
		heapi(array, size, zb1, 0);
	}
}
