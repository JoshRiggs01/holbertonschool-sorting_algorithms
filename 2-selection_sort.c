#include "sort.h"

/**
*swap - swaps two elements in an array
*@xp: first element to be swapped
*@yp: seceond element to be swapped
*/
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
*selection_sort - sorts an array
*@array: the array to be sorted
*@size: the number of elements in the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
	{
		return;
	}

		for (i = 0; i < size - 1; i++)
		{
			min = array + i;
			for (j = i + 1; j < size; j++)
			{
				min = (array[j] < *min) ? (array + j) : min;
			}
			if ((array + i) != min)
			{
				swap(array + i, min);
				print_array(array, size);
			}
		}
}