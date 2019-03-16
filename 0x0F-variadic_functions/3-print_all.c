#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - print all arguments using given data types
 * @format: data type of each argument (c, i, f, s)
 */
void print_all(char const * const format, ...)
{
	char const *sep = "", *str, *sub;
	va_list list;

	va_start(list, format);
	sub = format;
	while (format && *sub != '\0')
	{
		if (*sub == 'c' || *sub == 'i' || *sub == 'f' || *sub == 's')
			printf("%s", sep);
		switch (*sub++)
		{
		case 'c':
			printf("%c", va_arg(list, int));
			break;
		case 'i':
			printf("%i", va_arg(list, int));
			break;
		case 'f':
			printf("%f", va_arg(list, double));
			break;
		case 's':
			str = va_arg(list, char *);
			if (str == NULL)
			{
				printf("(nil)");
				break;
			}
			printf("%s", str);
			break;
		}
		sep = ", ";
	}
	printf("\n");
	va_end(list);
}
