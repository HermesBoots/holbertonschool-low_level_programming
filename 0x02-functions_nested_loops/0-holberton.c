#include "holberton.h"

/**
 * main - Entry point, prints a string
 *
 * Return: 0
 */
int main(void)
{
	char message[] = "Holberton";
	int size = sizeof(message) - sizeof(char);
	int i;

	for (i = 0; i < size; i++)
		_putchar(message[i]);
	_putchar('\n');
	return (0);
}
