/**
 * _strspn - get length of prefix in a string consisting of certain characters
 * @str: string to check prefix of
 * @accept: string containing characters considered part of prefix
 *
 * Return: number of characters in prefix
 */
unsigned int _strspn(char *str, char *accept)
{
	char *sub;
	unsigned int ret = 0;

	for (; *str; str++)
	{
		for (sub = accept; *sub; sub++)
		{
			if (*str == *sub)
			{
				ret++;
				break;
			}
		}
		if (!*sub)
			break;
	}
	return (ret);
}
