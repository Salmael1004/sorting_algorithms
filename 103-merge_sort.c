#include "sort.h"

/**
 * merge_sort - sort array
 * @array: array of ints to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *zb1;

	if (!array || size < 2)
		return;

	zb1 = malloc(sizeof(int) * size);

	merge_recu(zb1, array, 0, size);
	free(zb1);
}

/**
 * merge_recursion - recursive function
 * @zb1: copy array
 * @array: array to merge sort
 * @left: index of the left element
 * @right: index of the right element
 */
void merge_recu(int *zb1, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		merge_recu(zb1, array, left, middle);
		merge_recu(zb1, array, middle, right);
		merge_sub(zb1, array, left, middle, right);
	}
}

/**
 * merge_subarray - merges subarrays
 * @zb1: copy array
 * @array: array to merge
 * @left: index of the left element
 * @middle: index of the middle element
 * @right: index of the right element
 */
void merge_sub(int *zb1, int *array, size_t left,
		size_t middle, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle  - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
			zb1[k] = array[i++];
		else
			zb1[k] = array[j++];
	}

	while (i < middle)
		zb1[k++] = array[i++];
	while (j < right)
		zb1[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = zb1[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
