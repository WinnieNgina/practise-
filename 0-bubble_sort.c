#include "sort.h"
/**
 * bubble_sort -  sorts an array of integers in ascending order using the Bubble sort algorithm
 * array: the array of integers to be sorted
 * size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t j,i;
	int temp;
	int swap;

	if (size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		for (j = 1; j < (size - i); j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j -1];
				array[j - 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
		{
			return;
		}
	}
}
