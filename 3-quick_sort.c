#include "sort.h"

/**
 * quick - quick sorting
 * @array: array
 * @low: first element of the array
 * @high: last element of the array
 * @size: size
 * Return: Always 0
 */


void quick(int *array, int low, int high, size_t size)
{
	if (array == NULL || size < 2)
		return;
	if (low < high)
	{
		int pi = lomuto(array, low, high, size);

		quick(array, low, pi - 1, size);
		quick(array, pi + 1, high, size);
	}
}


/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array
 * @size: size
 * Return: Always 0
 */

void quick_sort(int *array, size_t size)
{
	quick(array, 0, size - 1, size);
}

/**
 * swap_array - swap two elements
 * @i: first element to swap
 * @j: second element to swap
 * Return: Always 0
 */

void swap_array(int *i, int *j)

{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * lomuto - lomuto partititon scheme
 * @array: array
 * @size: size
 * @izq: first element
 * @der: last element
 * Return: Always 0
 */


int lomuto(int *array, int izq, int der, size_t size)
{
	int pivot = array[der];
	int i = (izq - 1);
	int j = izq;

	for (j = izq; j < der; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_array(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);

		}

	}
	swap_array(&array[i + 1], &array[der]);
	if (array[++i] != array[der])
		print_array(array, size);

	return (i);
}