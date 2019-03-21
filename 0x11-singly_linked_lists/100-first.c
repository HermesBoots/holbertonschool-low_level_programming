#include <stdio.h>


/**
 * setup - prints some text before main executes
 */
void __attribute__ ((constructor)) setup()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
