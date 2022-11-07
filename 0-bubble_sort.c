#include "sort.h"
/**
 * bubble_sort - a function that sort an @array of intergers of size @size
 * in ascending order using the bubble sort algorithm
 * @array: array of interegers to be sorted of size @size
 * @size: the size of @array to be sorted
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swap, temp;
	size_t i, j;

	swap = 0;
	temp = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap++;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
