#include "sort.h"
/**
 * swap - swaps two ints
 * @a: int 1
 * @b: int 2
 */


void swap(int *a, int *b);
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sorts an array in ascending order using shell sort algorithm
 * using the knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t space, i, j;

	if (!array || size < 2)
		return;

	for (space = 1; space < (size / 3);)
	{
		space = space * 3 + 1;
	}
	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				swap(array + j, array + (j - space));
				j -= space;
			}
		}
		print_array(array, size);
	}
}
