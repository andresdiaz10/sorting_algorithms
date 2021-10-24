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
 * bubble_sort - sort a array in ascending order
 * @array - Array to sort
 * @size - Size of the array
 *
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;
	for (i = 0 ; i < size - 1 ; i++)
		for(j = 0 ; j < size - i - 1 ; j++)
			if (array[j] > array[j + 1])
			{
				swap_int(array + j, array + j + 1);
				print_array(array, size);
			}
}
