#define NULL ((void *)0)

/**
 * _strstr - find first occurrence of a substring in a larger string
 * @haystack: string to search through
 * @needle: substring to search for
 *
 * Return: pointer to first substring if found, NULL otherwise
 */
char *_strstr(char *haystack, char *needle)
{
	char *search, *test;

	for (; *haystack; haystack++)
	{
		search = haystack;
		test = needle;
		while (*search && *test && *search == *test)
		{
			search++;
			test++;
		}
		if (!*test)
			return (haystack);
	}
	return (NULL);
}
