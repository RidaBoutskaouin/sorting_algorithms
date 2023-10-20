#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, int size)
{
	int i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;

				print_array(array, size);
			}
		}
	}
}