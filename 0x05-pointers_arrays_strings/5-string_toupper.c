/**
 * string_toupper - converts string to all upper case
 * @str: string to convert
 *
 * Return: str
 */
char *string_toupper(char *str)
{
	char *sub;

	for (sub = str; *sub; sub++)
	{
		if (*sub >= 'a' && *sub <= 'z')
			*sub -= 32;
	}
	return (str);
}
