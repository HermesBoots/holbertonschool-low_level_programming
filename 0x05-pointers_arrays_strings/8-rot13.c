#include <stdio.h>

#define ROTATION_LEN 78

/**
 * rot13 - encodes a string using rot13
 * @str: string to encode
 *
 * Return: str
 */
char *rot13(char *str)
{
	static char const rotation[] = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
	};
	int i;
	char *sub;

	for (sub = str; *sub; sub++)
	{
		for (i = 0; i < ROTATION_LEN; i++)
		{
			if (*sub == rotation[i])
			{
				*sub = rotation[i + 13];
				break;
			}
		}
	}
	return (str);
}
