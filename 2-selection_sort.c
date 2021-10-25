#include "sort.h"

/**
 * swap_int - swap two int's
 * @first_number: first number to swap
 * @second_number: second number to swap
 *
 * Return: None
 */
void swap_int(int *first_number, int *second_number)
{
	int temp;

	temp = *first_number;
	*first_number = *second_number;
	*second_number = temp;
}

/**
 * selection_sort - sort a array in ascending order using selection sort
 * @array: array to sort
 * @size: size of the array
 *
 * Return: None
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_number;

	if (!array || size < 2)
		return;
	for (i = 0 ; i < size - 1 ; i++)
	{
		min_number = array + i;
		for (j = i + 1 ; j < size ; j++)
			if (array[j] < *min_number)
				min_number = array + j;
		if (&array[i] != min_number)
		{
			swap_int(array + min_number, array + i);
			print_array(array, size);
		}
	}
}
