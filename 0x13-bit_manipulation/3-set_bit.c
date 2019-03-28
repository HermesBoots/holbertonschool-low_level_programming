#define NULL ((void *)0)
/**
 * set_bit - set a bit at a specific index in an existing integer
 * @n: pointer to integer to change
 * @index: position of bit to set, counting least significant as 0
 *
 * Return: 1 if success, -1 if failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index >= 64)
		return (-1);
	*n |= 1 << index;
	return (1);
}
