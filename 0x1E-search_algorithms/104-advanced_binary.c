#include <stdio.h>
#include "search_algos.h"


/**
 * print_mem_range_advanced - print all integers between 2 addresses
 * @left: pointer to first element to print
 * @right: address after last element to print
 */
void print_mem_range_advanced(int const *left, int const *right)
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
 * do_advanced_binary - recursive helper function for advanced_binary
 * @array: pointer to first element in the array
 * @left: index to start searching at
 * @right: index to stop searching before
 * @value: value to search for
 * Return: index of value in array or -1 if not found
 */
int do_advanced_binary(int *array, size_t left, size_t right, int value)
{
	size_t middle;

	print_mem_range_advanced(array + left, array + right);
	if (left >= right)
		return (-1);
	middle = left + (right - left - 1) / 2;
	if (array[middle] > value)
		return (do_advanced_binary(array, left, middle, value));
	else if (array[middle] < value)
		return (do_advanced_binary(array, middle + 1, right, value));
	else if (array[left] != value)
		return (do_advanced_binary(array, left, middle + 1, value));
	return (middle);
}


/**
 * advanced_binary - perform a binary search on an array and find lowest index
 * @array: pointer to first element in the array
 * @size: number of elements in the array
 * @value: value to search for
 * Return: index of value in array or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (do_advanced_binary(array, 0, size, value));
}
