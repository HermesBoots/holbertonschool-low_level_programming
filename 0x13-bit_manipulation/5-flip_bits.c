/**
 * flip_bits - find the number of bits that need to change between two integers
 * @n: first number
 * @m: second number
 *
 * Return: number of bits that are different between n and m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int i, ret = 0;
	unsigned long int diff;

	diff = n ^ m;
	for (i = 0; i < 64; i++, diff >>= 1)
	{
		if ((diff & 1) == 1)
			ret++;
	}
	return (ret);
}
