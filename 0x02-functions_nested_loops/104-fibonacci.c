#include <limits.h>
#include <math.h>
#include <stdio.h>

#define SAFE 0
#define UNSAFE_SUM 1
#define UNSAFE 2

#define DIV_TRUNC(f) ((unsigned long)((f) / 100))
#define TRANSITION do { \
	lsb_curr = msb_curr % 100; \
	lsb_prev = msb_prev % 100; \
	lsb_next = lsb_curr + lsb_prev; \
	lsb_prev = lsb_curr; \
	lsb_curr = lsb_next; \
	flo_curr = flo_prev = msb_curr; \
	flo_curr += msb_prev; \
} while (0)


/**
 * main - Entry point, lists first 100 Fibonnaci numbers
 *
 * Return: 0
 */
int main(void)
{
	long double flo_curr, flo_next, flo_prev;
	signed int i, state = SAFE;
	unsigned char lsb_curr, lsb_next, lsb_prev;
	unsigned long int msb_curr = 1, msb_next, msb_prev = 1;

	for (i = 0; i < 98; i++)
	{
		switch (state)
		{
		case SAFE:
			printf("%lu, ", msb_curr);
			if (ULONG_MAX - msb_curr < msb_prev)
			{
				state = UNSAFE_SUM;
				continue;
			}
			msb_next = msb_curr + msb_prev;
			msb_prev = msb_curr;
			msb_curr = msb_next;
		break;
		case UNSAFE_SUM:
			TRANSITION;
			i--;
			state = UNSAFE;
		break;
		case UNSAFE:
			printf("%lu%02hu", DIV_TRUNC(flo_curr), lsb_curr % 100);
			if (i < 97)
				printf(", ");
			flo_next = flo_curr + flo_prev;
			flo_prev = flo_curr;
			flo_curr = flo_next;
			lsb_next = lsb_curr % 100 + lsb_prev % 100;
			lsb_prev = lsb_curr;
			lsb_curr = lsb_next;
		break;
		}
	}
	printf("\n");
	return (0);
}
