#include "sort.h"

/**
*bubble_sort - sorts array in ascending order
*@array: array to be sorted
*@size: size of array
*Return: none
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swap;

	/*edge case for already sorted array*/
	if (array == NULL || size < 2)
		return;

	/* loop to compare each array element*/
	for (i = 0; i < size - 1; ++i)
	{
	/*loop to compare array elements*/
		for (j = 0; j < size - i - 1; ++j)
		{
	/*compare two adjacent elements*/
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
	}
}