#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    
    quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - Recursive helper function for Quick Sort
 *
 * @array: The array to be sorted
 * @lo: The lower index of the partition to be sorted
 * @hi: The higher index of the partition to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
    int p;

    if (lo < hi)
    {
        p = partition(array, lo, hi, size);
        quick_sort_helper(array, lo, p - 1, size);
        quick_sort_helper(array, p + 1, hi, size);
    }
}

/**
 * partition - Partitions an array using the Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @lo: The lower index of the partition to be partitioned
 * @hi: The higher index of the partition to be partitioned
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot element
 */
int partition(int *array, int lo, int hi, size_t size)
{
    int i, j, temp, pivot;

    pivot = array[hi];
    i = lo - 1;

    for (j = lo; j < hi; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[hi])
    {
        temp = array[i + 1];
        array[i + 1] = array[hi];
        array[hi] = temp;
        print_array(array, size);
    }

    return i + 1;
}
