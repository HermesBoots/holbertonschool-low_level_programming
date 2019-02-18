#include <stdio.h>

/**
 * print_array - prints some elements from an array
 * @a: the array
 * @n: the number of elements to print
 */
void print_array(int *a, int n)
{
	int *end = a + n - 1, *sub;

	for (sub = a; sub < end; sub++)
		printf("%d, ", *sub);
	if (n > 0)
		printf("%d", *sub);
	printf("\n");
}
