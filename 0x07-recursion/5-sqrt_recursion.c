/**
 * do_sqrt - does the work of _sqrt_recursion with an extra parameter
 * @target: number to find square root of
 * @test: number to check if it's the square root
 *
 * Return: square root of target or -1 if there isn't one
 */
int do_sqrt(int target, int test)
{
	if (test * test > target || test * test < test)
		return (-1);
	else if (test * test < target)
		return (do_sqrt(target, test + 1));
	return (test);
}

/**
 * _sqrt_recursion - return square root of a number
 * @n: number to get root of
 *
 * Return: square root of n
 */
int _sqrt_recursion(int n)
{
	return (do_sqrt(n, 0));
}
