#include "sort.h"

/**
 * quick_swap - swap elements of array.
 * @a: integer.
 * @b:integer.
 * @array:array of integer.
 * @size: size of integer.
 *
 * Return: (void).
*/

void quick_swap(int *a, int *b, int *array, size_t size)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;

	if (*a != *b || array[*a] != array[*b])
		print_array(array, size);
}

/**
 * quick_partition - Lomuto partition.
 * @array: array of  integer.
 * @min: lower integer to compare.
 * @max: higer integer to compare.
 * @size: size of array.
 *
 * Return: new min or max.
*/

int quick_partition(int *array, int min, int max, size_t size)
{
	int piv = array[max];
	int i = min - 1, j;

	for (j = min; j <= max - 1; j++)
	{
		if (array[j] <= piv)
		{
			i = i + 1;
			quick_swap(&array[i], &array[j], array, size);
		}
	}
	quick_swap(&array[i + 1], &array[max], array, size);
	return (i + 1);
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
}
