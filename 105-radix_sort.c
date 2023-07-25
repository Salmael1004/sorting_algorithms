#include "sort.h"

int zero_base(int *array, int size);
void radix_count(int *array, size_t size, int zb1, int *buff);
void radix_sort(int *array, size_t size);

/**
 * zero_base - maximum value in an array
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int zero_base(int *array, int size)
{
	int zb1, i;

	for (zb1 = array[0], i = 1; i < size; i++)
	{
		if (array[i] > zb1)
			zb1 = array[i];
	}

	return (zb1);
}

/**
 * radix_count - Sort the significant digits of an array of integers
 * @array: An array of integers.
 * @size: The size of the array.
 * @zb1: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_count(int *array, size_t size, int zb1, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / zb1) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / zb1) % 10] - 1] = array[i];
		count[(array[i] / zb1) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 * Implements the LSD radix sort algorithm
 * Print array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int up, zb1, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	up = zero_base(array, size);
	for (zb1 = 1; up / zb1 > 0; zb1 *= 10)
	{
		radix_count(array, size, zb1, buff);
		print_array(array, size);
	}

	free(buff);
}
