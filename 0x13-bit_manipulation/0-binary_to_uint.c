#define NULL ((void *)0)
/**
 * binary_to_uint - convert string containing binary number to integer
 * @b: string to convert
 *
 * Return: converted number, also 0 if conversion fails
 */
unsigned int binary_to_uint(char const *b)
{
	unsigned int ret = 0;

	if (b == NULL)
		return (0);
	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);
		ret = (ret << 1) + (*b++ - '0');
	}
	return (ret);
}
