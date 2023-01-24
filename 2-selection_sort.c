#include "sort.h"
/**
 * swap - swaps two ints
 * @a: int 1
 * @b: int 2
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}

		if (i != k)
		{
			swap(&array[k], &array[i]);
			print_array(array, size);
		}
	}
}
