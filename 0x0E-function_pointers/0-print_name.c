#define NULL ((void *)0)

/**
 * print_name - passes an argument to another function
 * @name: string to pass
 * @f: function to pass name to
 */
void print_name(char *name, void (*f)(char *))
{
	if (f != NULL)
		f(name);
}
