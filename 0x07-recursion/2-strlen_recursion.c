/**
 * _strlen_recursion - return length of a string
 * @str: string to check
 *
 * Return: string length
 */
int _strlen_recursion(char *str)
{
	if (*str)
		return (_strlen_recursion(++str) + 1);
	return (0);
}
