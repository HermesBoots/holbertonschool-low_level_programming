#include <stdio.h>
#include "search_algos.h"


/**
 * print_mem_range - print all integers between 2 addresses
 * @left: pointer to first element to print
 * @right: address after last element to print
 */
void print_mem_range(int const *left, int const *right)
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
 * binary_search - perform a binary search on an array
 * @array: pointer to first element in the array
 * @size: number of elements in the array
 * @value: value to search for
 * Return: index of value in array or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left, middle, right;

	left = 0, middle = (size - 1) / 2, right = size;
	while (right > left)
	{
		print_mem_range(array + left, array + right);
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
