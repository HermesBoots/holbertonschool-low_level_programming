/**
 * _strncpy - copy up to n bytes from src into dest
 * @dest: the buffer to copy into
 * @src: the string to copy
 * @n: the maximum number of characters to copy
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *sub;

	for (sub = dest; *src && n; sub++, src++, n--)
		*sub = *src;
	while (n--)
		*sub++ = '\0';
	return (dest);
}
