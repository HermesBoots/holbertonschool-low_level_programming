/**
 * _memcpy - copy bytes from one buffer to another
 * @dest: buffer to copy into
 * @src: buffer to copy from
 * @count: number of bytes to copy
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int count)
{
	char *sub;

	for (sub = dest; count; src++, sub++, count--)
		*sub = *src;
	return (dest);
}
