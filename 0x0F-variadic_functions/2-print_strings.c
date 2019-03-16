#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - print all string arguments with given separator
 * @separator: separator between strings, NULL for no separator
 * @n: number of arguments to print
 */
void print_strings(char const *separator, unsigned int const n, ...)
{
	char *str;
	int i;
	va_list list;

	i = n;
	if (i == 0)
		return;
	va_start(list, n);
	while (i--)
	{
		str = va_arg(list, char *);
		if (str)
			printf("%s", str);
		else
			printf("(nil)");
		if (i && separator)
			printf("%s", separator);
	}
	printf("\n");
	va_end(list);
}
