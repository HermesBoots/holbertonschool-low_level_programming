/**
 * do_is_palindrome - test whether left and right pointers match, then continue
 * @left: pointer to left side of string
 * @right: pointer to right side of string, mirroring left
 *
 * Return: 1 if string is palindrome, 0 if it isn't
 */
int do_is_palindrome(char *left, char *right)
{
	if (left >= right)
		return (1);
	else if (*left != *right)
		return (0);
	return (do_is_palindrome(left + 1, right - 1));
}

/**
 * _strlen - return length of string
 * @str: string to check
 *
 * Return: length of str
 */
int _strlen(char *str)
{
	if (*str)
		return (_strlen(str + 1) + 1);
	return (0);
}

/**
 * is_palindrome - test whether a string is a palindrome
 * @str: string to check
 *
 * Return: 1 if str is a palindrome, 0 if it isn't
 */
int is_palindrome(char *str)
{
	int len;

	len = _strlen(str);
	return (do_is_palindrome(str, str + len - 1));
}
