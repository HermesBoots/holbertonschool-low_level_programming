/**
 * _pow_recursion - perform exponentiation
 * @base: number to raise to a power
 * @exp: power to raise base to
 *
 * Return: result of calculation
 */
int _pow_recursion(int base, int exp)
{
	if (exp > 0)
		return (base * _pow_recursion(base, exp - 1));
	else if (exp == 0)
		return (1);
	else
		return (-1);
}
