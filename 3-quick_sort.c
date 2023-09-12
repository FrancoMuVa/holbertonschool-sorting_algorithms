#include "sort.h"

/**
 * quick_partition - Lomuto partition.
 * @array: array of  integer.
 * @min:lower integer to compare.
 * @max:higer integer to compare.
 * @size: size of array.
 *
 * Return: new min or max.
*/

int quick_partition(int *array, int min, int max, size_t size)
{
	int piv = array[max], aux = 0;
	int j = min - 1, i;

	for (i = min; i <= max - 1; i++)
	{
		printf("if (%d <= %d)\n", array[i], piv);
		if (array[i] <= piv)
		{
			j++;
			aux = array[j];
			array[j] = array[i];
			array[i] = aux;
		}
	}
	if (min != 0)
		print_array(array, size);
	aux = array[j + 1];
	array[j + 1] = array[max];
	array[max] = aux;

	if (min == 0)
		print_array(array, size);
	return (j + 1);
}

/**
 * quick_recursive - Function to perform recursion.
 * @array: array of integers.
 * @min: integer.
 * @max: integer.
 * @size: size of array.
 *
 * Return: (void).
*/

void quick_recursive(int *array, int min, int max, size_t size)
{
	int retu;

	if (min < max)
	{
		retu = quick_partition(array, min, max, size);
		quick_recursive(array, min, retu - 1, size);
		quick_recursive(array, retu + 1, max, size);
	}
}

/**
 * quick_sort - Algorithm to sort an array of integers.
 * @array: The array of integers.
 * @size: Size of array.
 *
 * Return: (void)
*/

void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	quick_recursive(array, 0, size - 1, size);
	print_array(array, size);
}
