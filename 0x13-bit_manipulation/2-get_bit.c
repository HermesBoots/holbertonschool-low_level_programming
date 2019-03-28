/**
 * get_bit - get a specific bit from an integer
 * @n: integer to get bits from
 * @index: which bit to get, counting the least significant as 0
 *
 * Return: value of bit, -1 if bit doesn't exist
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= 64)
		return (-1);
	return (n >> index & 1);
}
