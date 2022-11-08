#include "sort.h"

/**
 * quick_sort -orders an array of itegers @array
 * of @size in ascending order using the quick_sort algorithm
 *
 * @array: integer array of size @size to be ordered
 *
 * @size: size of @array to be sorted
 *
 * Return: Nothing sorts in place
 */
void quick_sort(int *array, size_t size)
{
	recursive_quicksort(array, size, 0, size - 1);
}

/**
 * recursive_quicksort -recursive helper function to order.
 *
 * @arr: integer array to be ordered
 *
 * @size: size of array being ordered in totality
 *
 * @lo: lower bound of @arr subarray to be recursivley ordered
 *
 * @hi: higher bound of @arr subarray to be recursivley ordered
 *
 * Return: Nothing just sorts in place
 */
void recursive_quicksort(int *arr, size_t size, ssize_t lo, ssize_t hi)
{
	ssize_t pivot_index;

	if (lo >= hi || lo < 0)
		return;
	pivot_index = partition(arr, size, lo, hi);
	recursive_quicksort(arr, size, lo, pivot_index - 1);
	recursive_quicksort(arr, size, pivot_index + 1, hi);
}

/**
 * partition -finds the pivot to base ordering on
 *
 * @arr: integer array to be ordered
 *
 * @size: size of array being ordered in totality
 *
 * @lo: lower bound of @arr subarray to find pivot
 *
 * @hi: higher bound of @arr subarray to find pivot
 *
 * Return: pivot index that contains element already in this subarray
 */
ssize_t partition(int *arr, size_t size, ssize_t lo, ssize_t hi)
{
	ssize_t index, j;
	int pivot, temp;

	pivot = arr[hi];
	index = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (arr[j] <= pivot)
		{
			index++;
			if (arr[index] == arr[j])
				continue;
			temp = arr[j];
			arr[j] = arr[index];
			arr[index] = temp;
			print_array(arr, size);
		}
	}
	index++;
	if (arr[index] == arr[hi])
		return (index);
	temp = arr[hi];
	arr[hi] = arr[index];
	arr[index] = temp;
	print_array(arr, size);
	return (index);
}
