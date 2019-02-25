/**
 * _memset - fill a buffer with a byte value
 * @buff: buffer to fill
 * @val: value to fill with
 * @count: number of bytes to fill
 *
 * Return: buff
 */
char *_memset(char *buff, char val, unsigned int count)
{
	char *sub;

	for (sub = buff; count; count--, sub++)
		*sub = val;
	return (buff);
}
