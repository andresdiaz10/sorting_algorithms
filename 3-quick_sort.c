#include "sort.h"

/**
 * lomuto - algorithm to partition an array into two
 * parts based on a given condition.
 * @array: array to be sorted
 * @low: lowest idx
 * @high: highest idx
 * @size: the size of the @array
 * Return: the idx of partition
 */
size_t lomuto(int *array, int low, int high, size_t size)
{
	int pivot, i, j, aux, temp;

	pivot = array[high];
	i = low;
	j = low;

	while (i < high)
	{
		if (pivot >= array[i])
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			if (array[i] != array[j])
				print_array(array, size);
			j++;
		}
		i++;
	}
	temp = array[j];
	array[j] = high;
	high = temp;
	if (array[j] != high)
		print_array(array, size);
	return (j);
}

/**
 * sort_array - sorts an array of integers in ascending order
 * implementing the Lomuto partition scheme.
 * @array: array to be sorted
 * @low: lowest idx
 * @high: highest idx
 * @size: the size of the @array
 */
void sort_array(int *array, int low, int high, size_t size)
{
	int idx;

	if (low < high)
	{
		idx = lomuto(array, low, high, size);
		sort_array(array, low, high - 1, size);
		sort_array(array, idx + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: the size of the @array
 */
void quick_sort(int *array, size_t size)
{
	sort_array(array, 0, size - 1, size);
}
