#define NULL ((void *)0)
/**
 * clear_bit - clear a certain bit in an existing integer
 * @n: pointer to integer to change
 * @index: which bit to change, counting least significant as 0
 *
 * Return: 1 if success, -1 if failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index >= 64)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
