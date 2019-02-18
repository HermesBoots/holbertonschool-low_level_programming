/**
 * _strcpy - copy a string
 * @dest: the location to copy the source to
 * @src: the string to copy
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	char *subD, *subS;

	for (subD = dest, subS = src; *subS; subD++, subS++)
		*subD = *subS;
	*subD = '\0';
	return (dest);
}
