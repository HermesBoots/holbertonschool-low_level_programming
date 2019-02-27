/**
 * factorial - calculate factorial
 * @n: number whose factorial to return
 *
 * Return: the factorial of n
 */
int factorial(int n)
{
	if (n > 0)
		return (n * factorial(n - 1));
	else if (n == 0)
		return (1);
	else
		return (-1);
}
