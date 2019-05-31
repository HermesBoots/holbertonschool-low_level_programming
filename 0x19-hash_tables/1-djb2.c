/**
 * hash_djb2 - hash function taken from Dan Bernstein
 * @str: null-terminated data to hash
 *
 * Return: hash value
 */
unsigned long int hash_djb2(unsigned char const *str)
{
	unsigned long ret = 5381;
	unsigned char c;

	c = *str;
	while (c != '\0')
	{
		ret = ((ret << 5) + ret) + c;
		c = *str++;
	}
	return (ret);
}
