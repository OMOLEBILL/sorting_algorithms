#include "sort.h"

/**
 * selection_sort -orders an array of itegers @array
 * of @size in ascending order using the selection_sort algorithm
 *
 * @array: integer array of size @size ro be ordered
 *
 * @size: size of @array to be sorted
 *
 * Return: Nothing sorts in place
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smallest, index;

	smallest = index = 0;
	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				index = j;
			}
		}
		if (array[i] == smallest)
			continue;
		array[index] = array[i];
		array[i] = smallest;
		print_array(array, size);
	}
}
