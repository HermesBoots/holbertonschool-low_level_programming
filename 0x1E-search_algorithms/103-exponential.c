#include <stdio.h>
#include "search_algos.h"


/**
 * print_mem_range_bonus - print all integers between 2 addresses
 * @left: pointer to first element to print
 * @right: address after last element to print
 */
void print_mem_range_bonus(int const *left, int const *right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		printf("%d", *left);
		if (left < right - 1)
			printf(", ");
		else
			printf("\n");
		left++;
	}
}


/**
 * binary_search_bonus - perform a binary search on an array
 * @array: pointer to first element in the array
 * @size: number of elements in the array
 * @value: value to search for
 * Return: index of value in array or -1 if not found
 */
int binary_search_bonus(int *array, size_t size, int value)
{
	size_t left, middle, right;

	left = 0, middle = (size - 1) / 2, right = size;
	while (right > left)
	{
		print_mem_range_bonus(array + left, array + right);
		if (array[middle] == value)
			return (middle);
		if (array[middle] > value)
		{
			right = middle;
			middle = left + (right - left - 1) / 2;
		}
		else
		{
			left = middle + 1;
			middle = left + (right - left - 1) / 2;
		}
	}
	return (-1);
}


/**
 * exponential_search - search a finite array using exponential search
 * @array: pointer to first value in array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index of value in array or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	int result;
	size_t index = 0, limit;

	if (size == 0 || (size == 1 && *array != value))
		return (-1);
	if (size == 1 && *array == value)
		return (0);
	for (limit = 1; limit < size; limit *= 2)
	{
		if (array[limit] > value)
			break;
		index = limit;
		printf("Value checked array[%lu] = [%d]\n", limit, array[limit]);
	}
	limit = limit >= size - 1 ? size  - 1 : limit;
	printf("Value found between indexes [%lu] and [%lu]\n", index, limit);
	result = binary_search_bonus(&array[index], limit - index + 1, value);
	if (result < 0)
		return (-1);
	return (index + result);
}
