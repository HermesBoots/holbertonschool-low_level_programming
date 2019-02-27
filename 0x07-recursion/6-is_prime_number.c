/**
 * do_is_prime - do the primality test of is_prime_number with needed parameter
 * @target: number to test primality of
 * @test: number to check divisibility of
 *
 * Return: 1 if target is prime, 0 if it isn't
 */
int do_is_prime(int target, int test)
{
	if (test < 2)
		return (1);
	else if (target % test == 0)
		return (0);
	return (do_is_prime(target, test - 1));
}

/**
 * is_prime_number - check if number is prime
 * @n: number to check primality of
 *
 * Return: 1 if target is prime, 0 if it isn't
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (do_is_prime(n, n - 1));
}
