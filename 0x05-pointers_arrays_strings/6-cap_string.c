/**
 * find_char - searches for a character in a string
 * @c: character to search for
 * @s: string to search in
 *
 * Return: '\0' if character not found, c otherwise
 */
char find_char(char c, char const *s)
{
	while (*s)
	{
		if (c == *s++)
			return (c);
	}
	return ('\0');
}

/**
 * cap_string - make the first letter of each word in a string upper case
 * @str: the string to convert
 *
 * Return: str
 */
char *cap_string(char *str)
{
	char *sub;
	static char const * const separators = ",;.!?\"(){} \t\n";

	for (sub = str; *sub; sub++)
	{
		if (sub == str || find_char(sub[-1], separators))
		{
			if (*sub >= 'a' && *sub <= 'z')
				*sub -= 32;
		}
	}
	return (str);
}
