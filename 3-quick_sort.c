#include "sort.h"

/**
 * swap - swap two numbers
 * @a: low number
 * @b: second number
 **/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - split array around pivot
 * @arr: array
 * @low: low element
 * @high: high element
 * @size: size
 * Return: i
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	if (i != j)
		print_array(arr, size);
	return (i);
}

/**
 * quickSort - sort a part of the list
* @arr: array
 * @low: low element
 * @high: high element
 * @size: size
 * Return: nothing
 */
void quickSort(int *arr, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high, size);
		quickSort(arr, low, pivot - 1, size);
		quickSort(arr, pivot + 1, high, size);
	}
}

/**
 * quick_sort - quick sort method array
 * @array: array
 * @size: size
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
