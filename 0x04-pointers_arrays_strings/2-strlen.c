/**
 * _strlen - get the length of a string
 * @s: the string
 *
 * Return: the string's length, not counting the trailing null
 */
int _strlen(char *s)
{
	char *sub;
	int count = 0;

	for (sub = s; *sub; sub++)
		count++;
	return (count);
}
