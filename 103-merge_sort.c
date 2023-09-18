#include "sort.h"

void merge(int *array, int *temp, int left, int mid, int right);
void top_down_split_merge(int *temp, int left, int right, int *array,
							size_t size);

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: the array of integers
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(size * sizeof(int));

	if (!temp)
		return;

	top_down_split_merge(temp, 0, size, array, size);
	free(temp);
}

/**
 * top_down_split_merge - recursively splits the array and then merges
 * the parts
 * @temp: temporary array to hold sorted values
 * @left: start index
 * @right: end index
 * @array: original array
 * @size: size of the array
 */
void top_down_split_merge(int *temp, int left, int right, int *array,
							size_t size)
{
	int mid, i;

	if (right - left <= 1)
		return;

	mid = (right + left) / 2;
	top_down_split_merge(temp, left, mid, array, size);
	top_down_split_merge(temp, mid, right, array, size);

	merge(array, temp, left, mid, right);
	for (i = left; i < right; i++)
		array[i] = temp[i];
}

/**
 * merge - merges two subarrays in sorted order
 * @array: original array
 * @temp: temporary array where merged values are stored
 * @left: start index of left subarray
 * @mid: start index of right subarray
 * @right: end index of right subarray
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i = left, j = mid, k;

	printf("Merging...\n");
	for (k = left; k < right; k++)
	{
		if (i < mid && (j >= right || array[i] <= array[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}

	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);
	printf("[Done]: ");
	print_array(temp + left, right - left);
}
