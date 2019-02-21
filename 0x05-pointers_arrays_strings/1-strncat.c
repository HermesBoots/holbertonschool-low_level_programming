/**
 * _strncat - concatenate up to n bytes from src onto dest
 * @dest: the buffer to concatenate onto
 * @src: the string to copy
 * @n: the maximum number of bytes to copy from src
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *sub;

	for (sub = dest; *sub; sub++)
		;
	for (; *src && n; src++, sub++, n--)
		*sub = *src;
	*sub = '\0';
	return (dest);
}
