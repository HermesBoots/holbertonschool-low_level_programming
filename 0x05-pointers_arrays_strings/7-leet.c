#define CHARS_CHANGED 10

/**
 * leet - convert a string to 1337 speak
 * @str: string to convert
 *
 * Return: str
 */
char *leet(char *str)
{
	static char const from[] = {
		'A', 'E', 'L', 'O', 'T',
		'a', 'e', 'l', 'o', 't'
	};
	static char const to[] = {
		'4', '3', '1', '0', '7',
		'4', '3', '1', '0', '7'
	};
	char *sub;
	int i;

	for (sub = str; *sub; sub++)
	{
		for (i = 0; i < CHARS_CHANGED; i++)
		{
			if (*sub == from[i])
			{
				*sub = to[i];
				break;
			}
		}
	}
	return (str);
}
