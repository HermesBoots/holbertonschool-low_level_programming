#include <stdarg.h>

/**
 * sum_them_all - calculate sum of all arguments
 * @n: number of following arguments
 *
 * Return: sum
 */
int sum_them_all(unsigned int n, ...)
{
	int sum = 0;
	va_list list;

	if (n == 0)
		return (0);
	va_start(list, n);
	while (n--)
		sum += va_arg(list, int);
	va_end(list);
	return (sum);
}
