/**
 * _strcat - concatenate string from dest onto src
 * @dest: the string buffer to concatenate onto
 * @src: the string to copy onto the other
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	char *sub;

	for (sub = dest; *sub; sub++)
		;
	for (; *src; src++, sub++)
		*sub = *src;
	*sub = '\0';
	return (dest);
}
