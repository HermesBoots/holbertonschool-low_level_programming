/**
 * _atoi - convert string to integer
 * @s: the string to find the integer in
 *
 * Return: the first number found in the string
 */
int _atoi(char *s)
{
	char *sub;
	unsigned char negative = 0;
	int ret = 0;

	for (sub = s; (*sub < '0' || *sub > '9') && *sub; sub++)
	{
		if (*sub == '-')
			negative = !negative;
	}

	for (; *sub >= '0' && *sub <= '9'; sub++)
	{
		ret *= 10;
		ret += *sub - '0';
	}

	if (negative)
		ret = -ret;

	return (ret);
}
