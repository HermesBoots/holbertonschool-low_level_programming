#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - print all arguments separated by given string
 * @separator: separator between each number, NULL for no separator
 * @n: number of arguments to print
 */
void print_numbers(char const *separator, unsigned int const n, ...)
{
	int i;
	va_list list;

	i = n;
	va_start(list, n);
	while (i--)
	{
		printf("%d", va_arg(list, int));
		if (i && separator)
			printf("%s", separator);
	}
	printf("\n");
	va_end(list);
}
