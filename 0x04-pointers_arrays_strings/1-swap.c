/**
 * swap_int - swaps the values of both arguments
 * @a: the first argument
 * @b: the second argument
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
