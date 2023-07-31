#include "sort.h"

/**
 * swap - function that swap the position of two elements into an
 * array
 * @array: the array
 * @item1: the array element
 * @item2: the array element
 */

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * lomuto_partition - program for lomuto partition sorting scheme
 * implementation
 * @array: the array
 * @first: the first array element
 * @last: the last array
 * @size: the size of array
 *Return: return the position of the last element sorted
 */

int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * qs - program/function for quicksort algorithm implementation
 * @array: the array
 * @first: the first array element
 * @last: the last array element
 * @size: the size of array
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - program/function that sort the array of integer in
 * an ascending order using algorithm
 * @array: the array
 * @size: the size of array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
