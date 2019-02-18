#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGITS "0123456789"
#define LOWER "abcdefghijklmnopqrstuvwxyz"
#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

/**
 * main - Entry point, generates strings with the checksum 0xAD4
 *
 * Return: 0
 */
int main(void)
{
	char choices[62] = DIGITS UPPER LOWER;
	char key[64] = {'\0'};
	int check = 0xad4, i, stop = check - 'z' * 2, sum;

	srand(time(0));

	for (i = 0, sum = 0; sum < stop; i++)
	{
		key[i] = choices[rand() % 62];
		sum += key[i];
	}
	stop = check - sum;
	key[i++] = stop++ / 2;
	key[i] = stop / 2;

	printf("%s\n", key);
	return (0);
}
