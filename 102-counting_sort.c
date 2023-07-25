#include "sort.h"

/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *out, up, num, j, l;
	size_t i, k, m, n;

	if (size < 2)
		return;

	up = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > up)
			up = array[i];

	count = malloc(sizeof(size_t) * (up + 1));
	out = malloc(sizeof(int) * size);

	for (j = 0; j <= up; j++)
		count[j] = 0;
	for (k = 0; k < size; k++)
	{
		num = array[k];
		count[num] += 1;
	}
	for (l = 1; l <= up; l++)
		count[l] += count[l - 1];
	print_array(count, up + 1);
	for (m = 0; m < size; m++)
	{
		out[count[array[m]] - 1] = array[m];
		count[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = out[n];

	free(count);
	free(out);
}
