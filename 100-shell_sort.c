#include "sort.h"

/**
* shell_sort - sort an array of integers
* @array: integers array
* @size: array size
* Return: none
*/
void shell_sort(int *array, size_t size)
{
	size_t base = 0, j, i;
	int zb1;

	if (size < 2)
		return;

	while ((base = base * 3 + 1) < size)
		;

	base = (base - 1) / 3;

	for (; base > 0; base = (base - 1) / 3)
	{
		for (i = base; i < size; i++)
		{
			zb1 = array[i];
			for (j = i; j >= base && zb1 <= array[j - base]; j -= base)
				array[j] = array[j - base];
			array[j] = zb1;
		}
		print_array(array, size);
	}
}
