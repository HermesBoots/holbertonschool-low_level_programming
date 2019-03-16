#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - print all arguments using given data types
 * @format: data type of each argument (c, i, f, s)
 */
void print_all(char const * const format, ...)
{
	char const accept[] = "cifs";
	char const *a, *str, *sub;
	va_list list;

	va_start(list, format);
	sub = format;
	while (*sub != '\0')
	{
		switch (*sub)
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
			str = va_arg(list, char const *);
			if (str)
				printf("%s", str);
			else
				printf("(nil)");
			break;
		}
		a = accept;
		while (*a != '\0')
		{
			if (*sub == *a && sub[1] != '\0')
				printf(", ");
			a++;
		}
		sub++;
	}
	printf("\n");
	va_end(list);
}
