#include <stdio.h>

/**
 * print_diagsums - print sum of diagonals in a square matrix
 * @arr: matrix to use
 * @size: dimensions of matrix
 */
void print_diagsums(int *arr, int size)
{
	int i, sum = 0;

	for (i = 0; i < size; i++)
		sum += arr[i * size + i];
	printf("%d, ", sum);
	sum = 0;
	for (i = 0; i < size; i++)
		sum += arr[i * size + size - i - 1];
	printf("%d\n", sum);
}
